"use strict";

import https from "https";
import fs from "fs";
import JSZip from "jszip";

const libsPath = "libs/";

function makeSureDirExists(path: string): void {
    if (!fs.existsSync(path)) fs.mkdirSync(path);
}

/**
 * @param run it must only contains calls to zip function
 * 
 * Must Call Time(s): 1
 */
export function dependencies(run: () => void): void {
    makeSureDirExists(libsPath);
    run();
}

export function zip(url: string): void {
    https.get(url, res => {
        const file = new Uint8Array(Number(res.headers["content-length"]));
        let fileSize = 0;
        res.on("data", chunk => {
            file.set(chunk, fileSize);
            fileSize += chunk.length;
        }).on("end", () => {
            JSZip.loadAsync(file).then(value => {
                for (const relativePath in value.files) {
                    if (value.files[relativePath].dir) {
                        makeSureDirExists(`${libsPath}${relativePath}`);
                    } else {
                        value.files[relativePath].async("uint8array").then(value => {
                            fs.writeFile(`${libsPath}${relativePath}`, value, err => {
                                if (err) throw err;
                            });
                        }, reason => {
                            throw new Error(reason);
                        });
                    }
                }
            }, reason => {
                throw new Error(reason);
            });
        }).on("error", err => {
            throw err;
        });
    });
}