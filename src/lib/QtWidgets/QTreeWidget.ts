import addon from '../utils/addon';
import { NodeWidget } from './QWidget';
import { NativeElement } from '../core/Component';
import { QAbstractScrollArea, QAbstractScrollAreaSignals } from './QAbstractScrollArea';
import { QTreeWidgetItem } from './QTreeWidgetItem';

/**
 
> Creates a tree view that uses a predefined tree model. 

* **This class is a JS wrapper around Qt's [QTreeWidget class](https://doc.qt.io/qt-5/qtreewidget.html)**

### Example

```javascript
const { QTreeWidget, QTreeWidgetItem } = require("@nodegui/nodegui");

const { QMainWindow, QTreeWidgetItem, QTreeWidget } = require("@nodegui/nodegui");

const win = new QMainWindow();
const tree = new QTreeWidget();

const item1 = new QTreeWidgetItem();
item1.setText(0, `item-1`);
const item2 = new QTreeWidgetItem();
item2.setText(0, `item-2`);
const item3 = new QTreeWidgetItem();
item3.setText(0, `item-3`);

tree.addTopLevelItem(item1);
tree.addTopLevelItem(item2);
tree.addTopLevelItem(item3);

// Add children to item1
const c1item1 = new QTreeWidgetItem(item1);
c1item1.setText(0, `c1item1`);
const c1item2 = new QTreeWidgetItem(item1);
c1item2.setText(0, `c1item1`);

win.setCentralWidget(tree);
win.show();
(global as any).win = win;
```
 */

export class QTreeWidget extends QAbstractScrollArea<QTreeWidgetSignals> {
    native: NativeElement;
    topLevelItems: Set<QTreeWidgetItem>;
    constructor();
    constructor(parent: NodeWidget<any>);
    constructor(parent?: NodeWidget<any>) {
        let native;
        if (parent) {
            native = new addon.QTreeWidget(parent.native);
        } else {
            native = new addon.QTreeWidget();
        }
        super(native);
        this.native = native;
        this.setNodeParent(parent);
        this.topLevelItems = new Set<QTreeWidgetItem>();
    }

    addTopLevelItem(item: QTreeWidgetItem): void {
        this.topLevelItems.add(item);
        this.native.addTopLevelItem(item.native);
    }
    setHeaderHidden(hide: boolean): void {
        this.native.setProperty('headerHidden', hide);
    }

    selectedItems(): QTreeWidgetItem[] {
        const nativeItems = this.native.selectedItems();
        return nativeItems.map(function(eachItem: QTreeWidgetItem) {
            return new QTreeWidgetItem(eachItem);
        });
    }
}

export interface QTreeWidgetSignals extends QAbstractScrollAreaSignals {
    itemSelectionChanged: () => void;
}
