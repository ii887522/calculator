"use strict";

import fs from "fs";
import { endsWithAny } from "./string_ext.js";
import pngToIco from "png-to-ico";
import { getFileNameWithoutExt } from "./synthetic_fs.js";
import createDesktopShortcuts from "create-desktop-shortcuts";

if (process.argv.length !== 8 || process.argv[2] !== "--release-path" || process.argv[4] !== "--resource-path" ||
    process.argv[6] !== "--ico")
    throw new Error(
        "Invalid Command Line!   Usage: node scripts/out/main/bundle.js --release-path <path> --resource-path <path> " +
        "--ico <file-name>"
    );
const outPath = "out/";
const outResPath = `${outPath}res/main/`;
fs.rmdirSync(outPath, { recursive: true });
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
pngToIco(`${process.argv[5]}${process.argv[7]}`).then(value => {
    fs.writeFile(`${outPath}${getFileNameWithoutExt(process.argv[7])}.ico`, value, err => {
        if (err) throw err;
    });
}, reason => {
    throw new Error(reason);
}).catch(reason => {
    throw new Error(reason);
});