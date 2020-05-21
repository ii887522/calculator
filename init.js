"use strict";

import { setSolutionConfigPaths, dependencies, zip, dll, libsPath } from "./scripts/out/main/init_system.js";

setSolutionConfigPaths("Calculator/Debug/", "Calculator/Release/");

dependencies(() => {
    zip("https://www.libsdl.org/release/SDL2-devel-2.0.12-VC.zip");
    zip("https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip");
    zip("https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip");
    dll(`${libsPath}SDL2-2.0.12/lib/x86/SDL2.dll`);
    dll(`${libsPath}SDL2_image-2.0.5/lib/x86/libpng16-16.dll`);
    dll(`${libsPath}SDL2_image-2.0.5/lib/x86/SDL2_image.dll`);
    dll(`${libsPath}SDL2_image-2.0.5/lib/x86/zlib1.dll`);
    dll(`${libsPath}SDL2_ttf-2.0.15/lib/x86/libfreetype-6.dll`);
    dll(`${libsPath}SDL2_ttf-2.0.15/lib/x86/SDL2_ttf.dll`);
});