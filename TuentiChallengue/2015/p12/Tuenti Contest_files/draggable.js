var Draggable = function(clickElement, winElement) {
    var clickElement = document.q(clickElement),
        winElement = document.q(winElement),
        sx, sy, nx, ny, ox, oy,
        mm = function(e) {
            nx = ox + e.clientX - sx;
            ny = oy + e.clientY - sy;
            if (nx < 0) nx = 0;
            if (ny < 0) ny = 0;
            winElement.style.left = nx + 'px';
            winElement.style.top = ny + 'px';
        },
        mu = function(e) {
            document.q('html').r('mousemove', mm, false);
            document.q('html').r('mouseup', mu, false);
        };
    clickElement.onmousedown = function(e) {
        if (e.button != 0) return false;
        var b = winElement.b();
        ox = b.left; oy = b.top;
        sx = e.clientX; sy = e.clientY;
        document.q('html').a('mousemove', mm, false);
        document.q('html').a('mouseup', mu, false);
        return false;
    };
};
