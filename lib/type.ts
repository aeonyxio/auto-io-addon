import { getKeyboardLayout } from "./get-keyboard-layout";
import { hotkey } from "./hotkey";
import { isLower } from "./is-lower";
import { Code } from "./key-codes";
import { KeyboardLayout } from "./keyboard-layout";
import { setKeyboardLayout } from "./set-keyboard-layout";
import { Key } from "./string-conversion";

export const type = async (str: string) => {
  const chars = [...str];

  for (let i = 0; i < chars.length; i++) {
    const char = chars[i];
    let keyData = Key[char.toUpperCase()];

    if (keyData === undefined) {
      throw new Error(`Cannot type key [${char}]. Currently unsupported`);
    }

    let keys = keyData.hotkey;

    if (!isLower(char)) {
      keys = [Code.SHIFT, ...keys];
    }

    let originalLayout: KeyboardLayout = KeyboardLayout.US;

    if (keyData.layout !== undefined) {
      originalLayout = getKeyboardLayout().layout;
      await setKeyboardLayout(keyData.layout);
    }

    await hotkey(...keys);

    if (keyData.layout !== undefined) {
      await setKeyboardLayout(originalLayout);
    }
  }
};
