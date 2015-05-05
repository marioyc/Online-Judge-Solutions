var CreatePhotoViewer = function (id) {
    var win = document.q(id),
        img = win.q('img'),
        close = function () {
            img.onerror = null;
            img.onload = null;
            img.src = '';
            win.className = 'win hide';
        },
        onerror = function () {
            Terminal.print('Error loading photo\n\n');
            close();
        },
        onload = function () {
            Terminal.print('Photo loaded!\n\n');
            win.className = 'win';
        },
        load = function (filename) {
            img.onerror = onerror;
            img.onload = onload;
            img.src = 'http://54.83.207.93:14333/'
                + OS.usr + '_' + OS.pwd + '_' + filename;
            //console.log(img.src);
            win.style.left = '75px';
            win.style.top = '75px';
        };
    win.className = 'win hide';
    win.q('.btn-close').onclick = close;
    return {
        load: load
    }
};
