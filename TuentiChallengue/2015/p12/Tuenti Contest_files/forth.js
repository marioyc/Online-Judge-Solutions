/**
 * Very basic interpreter of something like Forth
 * with a limited set of primitives
 *
 * Notes:
 * - Non primitive variables and words are case insensitive
 * - No shadowing (overwrites)
 * - All input space-like characters are converted to spaces
 * - Variables starting with $ are reserved
 * - Do not nest expressions of the same type
 */
var Forth = (function () {
    var dictionary,
        busy = false,
        nextAddr = 0,
        code = [],
        memory = [],
        stack = [],
        stdout = Function.prototype,
        finished = Function.prototype,
        chr = String.fromCharCode,
        ord = function (c) { return String(c).charCodeAt(0); },
        error = function(m) { stdout('\nError: ' + m + '\n'); code = []; },
        push = function (n) { stack.push(n|0); },
        pop = function () { if (!stack.length) { error('Stack underflow'); } return stack.pop(); },
        primitives = {
            interpret: function () {
                var interval = setInterval(function () {
                    var i = 1000;
                    while (i-- > 0) {
                        if (!code.length) {
                            busy = false;
                            clearInterval(interval);
                            return finished();
                        }
                        var w = code.shift().toUpperCase();

                        /*if(w == "DUP"){
                            console.log("x");
                        }*/

                        if (dictionary.hasOwnProperty(w)) {
                            dictionary[w]();
                        } else if (String(w).match(/^-?\d+$/)) {
                            push(w);
                        } else if (w.length) {
                            error(w + '?');
                        }
                    }
                }, 33);
            },
            colon: function () {
                var w = code.shift(), p = code.indexOf(';'), def = code.splice(0, p + 1);
                def.pop();
                dictionary[w.toUpperCase()] = function () {
                    code = def.concat(code);
                };
            },
            dotQuote: function () {
                var s = code.splice(0, code.indexOf('"') + 1);
                s.pop();
                stdout(s.join(' '));
            },
            ifThenElse: function () {
                var def, def0 = [], def1 = [], p = code.indexOf('ELSE');
                if (p >= 0 && p < code.indexOf('THEN')) {
                    def1 = code.splice(0, p + 1);
                    def1.pop();
                    p = code.indexOf('THEN');
                    def0 = code.splice(0, p + 1);
                    def0.pop();
                } else {
                    p = code.indexOf('THEN');
                    def1 = code.splice(0, p + 1);
                    def1.pop();
                }
                def = pop() ? def1 : def0;
                code = def.concat(code);
            },
            variable: function () {
                var addr = nextAddr++;
                var name = code.shift().toUpperCase();
                //console.log(name + " " + addr);
                dictionary[name] = function () {
                    push(addr);
                };
            },
            doLoop: function () {
                var p = code.indexOf('LOOP'), def = code.splice(0, p + 1), i = pop(), l = pop();
                def.pop();
                if (i++ < l) {
                    code = def.concat([String(l), String(i), 'DO'], def, ['LOOP'], code);
                }
            },
            datetime: function () {
                var d = new Date();
                ['Seconds', 'Minutes', 'Hours', 'Date', 'Month', 'FullYear'].forEach(function (f) {
                    push(d['get' + f]());
                });
            },
            rng: function () { push(Math.floor(Math.random() * pop())); },
            zeroGreaterThan: function () { push(0 < pop() ? -1 : 0); },
            zeroLessThan: function () { push(0 > pop() ? -1 : 0); },
            zeroEquals: function () { push(pop() ? 0 : -1); },
            dot: function () { stdout(pop()); },
            emit: function () { stdout(chr(pop())); },
            equal: function () { push(pop() === pop() ? -1 : 0); },
            mod: function () { var b = pop(), a = pop(); push(a % b); },
            abs: function () { push(Math.abs(pop())); },
            xor: function () {
                push(pop() ^ pop());
            },
            inc: function () { push(pop() + 1); },
            dec: function () { push(pop() - 1); },
            store: function () {
                memory[pop()] = pop();
            },
            fetch: function () {
                push(memory[pop()]);
            },
            comment: function () { code.splice(0, code.indexOf(')') + 1); },
            add: function () {
                push(pop() + pop());
            },
            substract: function () {
                var x = pop();
                push(pop() - x);
            },
            multiply: function () {
                push(pop() * pop());
            }
        };

    var reset = function () {
        code = [];
        stack = [];
        dictionary = {
            'INTERPRET': primitives.interpret,
            'VARIABLE': primitives.variable,
            'DATETIME': primitives.datetime,
            'EMIT': primitives.emit,
            'DO': primitives.doLoop,
            'MOD': primitives.mod,
            'ABS': primitives.abs,
            'RNG': primitives.rng,
            'XOR': primitives.xor,
            'IF': primitives.ifThenElse,
            '0=': primitives.zeroEquals,
            '0<': primitives.zeroLessThan,
            '0>': primitives.zeroGreaterThan,
            '1+': primitives.inc,
            '1-': primitives.dec,
            '."': primitives.dotQuote,
            ':': primitives.colon,
            '=': primitives.equal,
            '.': primitives.dot,
            '!': primitives.store,
            '@': primitives.fetch,
            '(': primitives.comment,
            'A': primitives.add,
            'S': primitives.substract,
            'PROCESS': primitives.multiply,
        };
    };

    var parseProgram = function (program) {
        return program.trim().replace(/\s+/g, ' ').split(' ');
    };

    var storeArgs = function (args) {
        var words = ['VARIABLE', '$ARGC', String(args.length), '$ARGC', '!'];
        args.forEach(function (v, i) {
            var name = '$ARG' + i;
            words.push('VARIABLE', name);
            if (isFinite(v)) {
                v = v|0;
                words.push('1', name, '!', String(v));
            } else {
                v = String(v);
                words.push(String(v.length), name, '!');
                words = words.concat(v.split('').map(ord).map(String));
            }
        });
        code = words.concat(code);
    };

    var interpreter = function (program, args, callback) {
        if (busy) {
            error('Busy');
        }
        reset();
        finished = callback;
        code = parseProgram(program);
        busy = true;
        storeArgs(args || []);
        primitives.interpret();
    };

    return {
        run: interpreter,
        redirect: function (f) { stdout = f; },
    };
}());
