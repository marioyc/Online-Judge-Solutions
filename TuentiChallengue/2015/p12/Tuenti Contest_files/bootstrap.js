(function(){
    var q = 'querySelector', p = 'prototype',
        a = 'addEventListener', r = 'removeEventListener',
        b = 'getBoundingClientRect',
        d = Document, e = Element, t = EventTarget;
    d[p].q = d[p][q];
    e[p].q = e[p][q];
    e[p].b = e[p][b];
    t[p].a = t[p][a];
    t[p].r = t[p][r];
    String[p].esc = function() {
        return this.replace(/[\u00A0-\u9999<>\&]/gim, function (c) {
            return ['&#', c.charCodeAt(0), ';'].join('');
        });
    };
    String[p].r = function() {
        return this.replace(/[a-zA-Z]/g, function(c) {
            return String.fromCharCode((c <= "Z" ? 0x5A : 0x7A) >= (c = c.charCodeAt(0) + 0xD) ? c : c - 0x1A);
        });
    };
    NodeList[p].forEach = Array[p].forEach;
}());

document.a('DOMContentLoaded', function() {
    var x = OS, m = '~ $ gryarg ebfrggn.pbageby.rfn.vag\n'.r() +
        'Gelvat 185.30.93.10...\n\n'.r() +
        'hfreanzr: '.r() + x['hfe'.r()] + '\n' +
        'cnffjbeq: '.r() + x['cjq'.r()] + '\n\n' +
        'Jrypbzr!\n'.r() +
        Date() + '\n\n';
    window.Terminal = CreateTerminal('#term', 'Terminal', '# ', m);
    window.PhotoViewer = CreatePhotoViewer('#photo');
    Draggable('#term .title', '#term');
    Draggable('#photo .title', '#photo');
    document.q('#term').style.left = '100px';
    document.q('#term').style.top = '100px';
    document.q('body').className = '';
    Terminal.focus();
    Forth.redirect(Terminal.print);
}, false);
