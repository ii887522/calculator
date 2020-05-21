"use strict";

import { getFileName } from "../main/fs_ext.js"

console.assert(getFileName("SDL2-2.0.12/lib/x86/SDL2.dll") === "SDL2.dll");
console.assert(getFileName("SDL2_image-2.0.5/lib/x86/libpng16-16.dll") === "libpng16-16.dll");
console.assert(getFileName("SDL2_ttf-2.0.15/lib/x86/libfreetype-6.dll") === "libfreetype-6.dll");