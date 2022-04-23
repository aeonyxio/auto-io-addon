const { writeFileSync } = require("fs");
const {
  screenCapture,
  getWindows,
  getWindowTitle,
  getWindowRect,
} = require("../dist/binding.js");

const test = async () => {
  const rect = getWindowRect(
    getWindows().find((id) => {
      return (
        "test_binding.js - auto-io-addon - Visual Studio Code" ===
        getWindowTitle(id)
      );
    })
  );
  const buffer = screenCapture(
    rect.x * 2.5,
    rect.y * 2.5,
    rect.width * 2.5,
    rect.height * 2.5
  );
  console.log(buffer);
  writeFileSync("test.png", buffer);
};

test().catch(console.error);
