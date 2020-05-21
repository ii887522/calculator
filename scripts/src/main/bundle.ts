"use strict";

import fs from "fs";

function makeSureDirExistsSync(path: string): void {
    if (!fs.existsSync(path)) fs.mkdirSync(path);
}

makeSureDirExistsSync("out/");