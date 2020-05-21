"use strict";

import { dependencies, zip } from "./scripts/out/init_system.js";

dependencies(() => {
    zip("https://www.libsdl.org/release/SDL2-devel-2.0.12-VC.zip");
});