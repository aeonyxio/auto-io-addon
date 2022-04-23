const { writeFileSync } = require("fs");
const { screenCapture } = require("../dist/binding.js");

const test = async () => {
  const buffer = screenCapture(0, 0, 500, 500);
  console.log(buffer);
};

test().catch(console.error);
