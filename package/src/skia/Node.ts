import type SkiaReadonlyValue from "@shopify/react-native-skia";

import type { SkJSIInstance } from "./JsiInstance";
import type { SkPaint } from "./Paint/Paint";

interface PaintProps {
  paint: SkPaint;
}

interface CircleProps extends PaintProps {
  r: number;
  cx: number | SkiaReadonlyValue<number>;
  cy: number | SkiaReadonlyValue<number>;
}

interface Node<T extends string = string> extends SkJSIInstance<T> {
  appendChild(node: Node): void;
}

export interface NodeFactory {
  MakeCanvas(): Node<"NodeCanvas">;
  MakeCircle(props: CircleProps): Node<"NodeCircle">;
}