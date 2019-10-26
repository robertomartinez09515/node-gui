import addon from "../../utils/addon";
import { NodeWidget } from "../QWidget";
import { EventWidget } from "../../core/EventWidget";
import { NativeElement } from "../../core/Component";
import { QKeySequence } from "../../QtGui/QKeySequence";
import { ShortcutContext } from "../../QtEnums";

export const QShortcutEvents = Object.freeze({
  activated: "activated",
  activatedAmbiguously: "activatedAmbiguously"
});

export class QShortcut extends EventWidget {
  native: NativeElement;
  constructor(parent: NodeWidget) {
    let native = new addon.QShortcut(parent.native);
    super(native);
    this.native = native;
  }
  setEnabled(enabled: boolean) {
    this.native.setEnabled(enabled);
  }
  setAutoRepeat(on: boolean) {
    this.native.setAutoRepeat(on);
  }
  setKey(keysequence: QKeySequence) {
    this.native.setKey(keysequence.native);
  }
  setContext(shortcutContext: ShortcutContext) {
    this.native.setContext(shortcutContext);
  }
}
