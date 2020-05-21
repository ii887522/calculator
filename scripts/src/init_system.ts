"use strict";

import https from "https";
import fs from "fs";
import JSZip from "jszip";

const libsPath = "libs/";

function makeSureDirExists(path: string): void {
    if (!fs.existsSync(path)) fs.mkdirSync(path);
}

/**
 * 
 */
export function dependencies(run: () => void): void {
    makeSureDirExists(libsPath);
    run;
}

/**
 * 
 */
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

                    } else {

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