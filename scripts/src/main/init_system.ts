"use strict";

import https from "https";
import fs from "fs";
import JSZip from "jszip";
import child_process from "child_process";

export const libsPath = "libs/";
let solutionConfigPaths: string[];

export function setSolutionConfigPaths(...value: string[]): void {
    solutionConfigPaths = value;
}

function makeSureCleanDirExists(path: string): void {
    fs.rmdirSync(path, { recursive: true });
    fs.mkdirSync(path);
}

function makeSureDirExists(path: string): void {
    fs.access(path, err => {
        if (!err) return;
        fs.mkdir(path, err => {
            if (err) throw err;
        });
    });
}

function makeSureSolutionConfigDirsExist(): void {
    for (const solutionConfigPath of solutionConfigPaths) makeSureDirExists(solutionConfigPath);
}

function makeSureNoDllsExist(path: string): void {
    for (const file of fs.readdirSync(path)) {
        if (!file.endsWith(".dll")) continue;
        fs.unlinkSync(`${path}${file}`);
    }
}

function makeSureNoDllsExistInSolutionConfigDirs(): void {
    for (const solutionConfigPath of solutionConfigPaths) makeSureNoDllsExist(solutionConfigPath);
}

/**
 * @param run it must only contains calls to zip or dll functions
 * 
 * Must Call Time(s): 1
 */
export function dependencies(run: () => void): void {
    if (process.argv.length === 2) {
        makeSureCleanDirExists(libsPath);
        makeSureSolutionConfigDirsExist();
    } else if (process.argv.length === 3 && process.argv[2] === "--dll") {
        makeSureNoDllsExistInSolutionConfigDirs();
    }
    run();
}

export function zip(url: string): void {
    if (process.argv.length !== 2) return;
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
                        fs.mkdirSync(`${libsPath}${relativePath}`);
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

process.on("exit", code => {
    if (process.argv.length === 2) child_process.fork("init.js", ["--dll"], { detached: true });
});

export function dll(path: string): void {
    if (process.argv.length !== 3 || process.argv[2] !== "--dll") return;
    // for (const solutionConfigPath of solutionConfigPaths) {
    //     fs.copyFile(path, `${solutionConfigPath}`);
    // }
}