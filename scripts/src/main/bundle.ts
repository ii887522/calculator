"use strict";

import fs from "fs";
import { endsWithAny } from "./string_ext.js";

if (process.argv.length !== 6 || process.argv[2] !== "--release-path" || process.argv[4] !== "--resource-path")
    throw new Error(
        "Invalid Command Line!   Usage: node scripts/out/main/bundle.js --release-path <path> --resource-path <path>"
    );
const outPath = "out/";
const outResPath = `${outPath}res/main/`;
fs.mkdirSync(outResPath, { recursive: true });
const args = [
    {
        src: process.argv[3],
        exts: [".exe", ".dll"],
        dest: outPath
    },
    {
        src: process.argv[5],
        exts: [".png"],
        dest: outResPath
    }
];
for (const arg of args) {
    fs.readdir(arg.src, (err, files) => {
        if (err) throw err;
        for (const file of files) {
            if (!endsWithAny(file, ...arg.exts)) continue;
            fs.copyFile(`${arg.src}${file}`, `${arg.dest}${file}`, err => {
                if (err) throw err;
            });
        }
    });
}