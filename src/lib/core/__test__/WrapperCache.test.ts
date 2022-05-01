import { QObject } from '../../QtCore/QObject';
import { QApplication } from '../../QtGui/QApplication';
import { CacheTestQObject } from './CacheTestQObject';

describe('WrapperCache using CacheTestQObject', () => {
    const qApp = QApplication.instance();
    qApp.setQuitOnLastWindowClosed(true);

    it('Cached foo', () => {
        const a = new CacheTestQObject();
        expect(a).not.toBeNull();

        const foo = a.foo();
        expect(foo).not.toBeNull();

        const foo2 = a.foo();
        expect(foo).toBe(foo2);
        expect(foo.native.__id__()).toBe(foo2.native.__id__());
    });

    it('clearFoo() and wrapper expiration', () => {
        const a = new CacheTestQObject();
        const foo = a.foo();
        a.clearFoo();
        expect(foo.native).toBeNull();
    });

    it('clearFoo() and new wrapper', () => {
        const a = new CacheTestQObject();
        const foo = a.foo();
        const fooId = foo.native.__id__();
        a.clearFoo();
        expect(foo.native).toBeNull();

        const foo2 = a.foo();
        expect(foo2).not.toBe(foo);
        expect(foo2.native.__id__()).not.toBe(fooId);
    });

    it('Cached foo and bar', () => {
        const a = new CacheTestQObject();
        const foo = a.foo();
        const bar = a.bar();
        expect(foo).not.toEqual(bar);
        expect(foo.native.__id__()).not.toEqual(bar.native.__id__());
    });

    it('QObject.parent() can be null', () => {
        const a = new QObject();
        expect(a.parent()).toBeNull();
    });

    it('QObject.parent() === QObject.parent()', () => {
        const a = new QObject();
        const b = new QObject(a);
        expect(a.native.__id__()).toEqual(b.parent().native.__id__());
        expect(a).toEqual(b.parent());
        (<any>a)['magic'] = true;
        expect((<any>b.parent())['magic']).toBe(true);
    });

    qApp.quit();
});
