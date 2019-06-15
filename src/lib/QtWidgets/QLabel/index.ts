import addon from "../../core/addon";
import { NodeWidget } from "../../QtGui/QWidget";

export class QLabel extends NodeWidget {
  native: any;
  constructor(parent?: NodeWidget) {
    let native;
    if (parent) {
      native = new addon.QLabel(parent.native);
    } else {
      native = new addon.QLabel();
    }
    super(native);
    this.native = native;
    this.parent = parent;
    // bind member functions
    this.setWordWrap.bind(this);
    this.setText.bind(this);
    this.text.bind(this);
  }
  setWordWrap(on: boolean) {
    this.native.setWordWrap(on);
  }
  setText(text: string | number) {
    this.native.setText(`${text}`);
  }
  text() {
    return this.native.text();
  }
}
