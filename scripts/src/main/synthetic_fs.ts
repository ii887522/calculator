"use strict";

export function getFileName(path: string): string {
    return path.substring(path.lastIndexOf("/") + 1);
}