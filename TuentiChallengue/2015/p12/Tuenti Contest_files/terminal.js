var CreateTerminal = function (id, title, prompt, msg) {
    var term = document.q(id),
        body = term.q('.body'),
        input = body.q('input'),
        scroll = function () {
            body.scrollTop = body.scrollHeight;
        },
        aux = '',
        print = function (str) {
            //console.log(str);
            //console.log(str);
            body.q('pre').innerHTML += str;
            //scroll();
        };
    term.q('h1').innerHTML = title;
    body.q('.prompt').innerHTML = prompt;
    term.onclick = input.focus.bind(input);
    input.onkeypress = function(e) {
        scroll();
        if (e.keyCode !== 13 || this.readOnly) { return; }
        input.readOnly = true;
        term.q('.bottom').className += ' hide';
        var cmd = this.value.trim().replace(/\s+/g, ' ').esc();
        this.value = '';
        print(prompt + cmd + '\n');
        OS.exec(cmd, function(stdout) {
            print((stdout || '') + '\n');
            term.q('.bottom').className = 'bottom';
            input.readOnly = false;
            scroll();
            input.focus();
        });
    };
    body.q('input').onkeydown = function(e) {
        if (e.keyCode === 9) {
            e.preventDefault();
            return false;
        }
    };
    print(msg);
    return {
        aux: aux,
        print: print,
        focus: input.focus.bind(input)
    };
};
