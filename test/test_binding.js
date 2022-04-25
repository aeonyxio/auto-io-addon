const { writeFileSync } = require("fs");
const {
  screenCapture,
  getWindows,
  getWindowTitle,
  getWindowRect,
  sleep,
  dpiAware,
} = require("../dist/binding.js");

const test = async () => {
  dpiAware();
  const getRect = () =>
    getWindowRect(
      getWindows().find((id) => {
        return (
          "test_binding.js - auto-io-addon - Visual Studio Code" ===
          getWindowTitle(id)
        );
      })
    );
  const rect = getRect();
  console.log(getRect());
  const buffer = screenCapture(rect.x, rect.y, rect.width, rect.height);
  console.log(buffer);
  writeFileSync("test.png", buffer);
  await sleep(5000);
  const buffer2 = screenCapture(rect.x, rect.y, rect.width, rect.height);
  console.log(buffer2);
  writeFileSync("test2.png", buffer2);
  console.log(getRect());
};

test().catch(console.error);
