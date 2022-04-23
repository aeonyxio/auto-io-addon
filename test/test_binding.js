const { writeFileSync } = require("fs");
const { screenCapture } = require("../dist/binding.js");

const test = async () => {
  screenCapture(0, 0, 500, 500);
};

test().catch(console.error);
