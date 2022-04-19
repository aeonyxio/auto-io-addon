import { Code } from "./key-codes";
import { keyDown } from "./key-down";
import { keyUp } from "./key-up";

export const hotkey = async (...keys: Code[]) => {
  const localKeys = [...keys];

  if (localKeys.length === 0) {
    throw new Error("Hotkey cannot be empty");
  }

  const nextKey = localKeys.shift()!;

  await keyDown(nextKey as Code);
  if (localKeys.length > 0) await hotkey(...localKeys);
  await keyUp(nextKey as Code);
};
