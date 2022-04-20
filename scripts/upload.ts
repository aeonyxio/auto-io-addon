import { execSync } from "child_process";
import { config } from "dotenv";

config();

const command = `prebuild --backend cmake-js --runtime napi --all --upload ${process.env.GITHUB_TOKEN}`;

execSync(command);
