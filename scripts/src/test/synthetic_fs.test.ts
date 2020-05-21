"use strict";

import { getFileName } from "../main/synthetic_fs.js"

console.assert(getFileName("SDL2-2.0.12/lib/x86/SDL2.dll") === "SDL2.dll");
console.assert(getFileName("SDL2_image-2.0.5/lib/x86/libpng16-16.dll") !== "SDL2.dll");
console.assert(getFileName("SDL2_image-2.0.5/lib/x86/libpng16-16.dll") === "libpng16-16.dll");