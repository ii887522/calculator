"use strict";

import fs from "fs";

export function makeSureCleanDirExists(path: string): void {
    fs.rmdirSync(path, { recursive: true });
    fs.mkdirSync(path);
}

export function getFileName(path: string): string {
    return path.substring(path.lastIndexOf("/") + 1);
}