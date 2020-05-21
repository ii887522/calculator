"use strict";

import fs from "fs";
import { makeSureCleanDirExists } from "./fs_ext.js";

if (process.argv.length !== 6 || process.argv[2] !== "--release-path" || process.argv[4] !== "--resource-path")
    throw new Error(
        "Invalid Command Line!   Usage: node scripts/out/main/bundle.js --release-path <path> --resource-path <path>"
    );
const outPath = "out/";
makeSureCleanDirExists(outPath);
fs.readdir(process.argv[3], (err, files) => {
    if (err) throw err;
    for (const file of files) {
        if (!(file.endsWith(".exe") || file.endsWith(".dll"))) continue;
        fs.copyFile(`${process.argv[3]}${file}`, `${outPath}${file}`, err => {
            if (err) throw err;
        });
    }
});