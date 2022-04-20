"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const child_process_1 = require("child_process");
const dotenv_1 = require("dotenv");
(0, dotenv_1.config)();
const command = `prebuild --backend cmake-js --runtime napi --all --upload ${process.env.GITHUB_TOKEN}`;
(0, child_process_1.execSync)(command);
