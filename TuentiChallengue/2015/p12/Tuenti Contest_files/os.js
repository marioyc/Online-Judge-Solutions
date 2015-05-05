var OS = (function() {
    var username = 'operator999',// + (100 + Math.floor(Math.random() * 900)), // MUST be operatorXXX
        password = '999999',//String(100000 + Math.floor(Math.random() * 900000)), // MUST be 6 digits long
        fail = function(cmd, cb) {
            cb('Unknown command: ' + cmd + '\n');
        },
        load = function(name) {
            console.log(name);
            return document.q('#' + name).innerHTML + '\n';
        },
        shouldHelp = function(argv, n) {
            return (argv.length - 1 !== (n | 0)) || ['-h','--help'].indexOf(argv[1]) >= 0;
        },
        forthExec = function(name, argv, cb) {
            Forth.run(load('stdlib') + load(name), argv, cb);
        },
        bin = {
            echo: function(argv, cb) {
                cb(argv.slice(1).join(' ') + '\n');
            },
            date: function(argv, cb) {
                if (shouldHelp(argv)) {
                    return cb('Display the current date\n');
                }
                cb(Date().toString() + '\n');
            },
            help: function(argv, cb) {
                if (shouldHelp(argv)) {
                    return cb('List available commands\n');
                }
                cb('Available commands: \n\n' + Object.keys(bin).sort().join('\n') + '\n');
            },
            reqant: function(argv, cb) {
                if (shouldHelp(argv, 2)) {
                    return cb('Request antenna access\nUsage: ' + argv[0] + ' &lt;username&gt; &lt;password&gt;\n');
                }
                if (argv[1] !== username || argv[2] !== password) {
                    return cb('Access denied\n');
                }
                forthExec('request-antenna-access', argv, cb);
            },
            photocmd: function(argv, cb) {
                if (shouldHelp(argv, 1)) {
                    return cb('Send photo command to Rosetta\n'
                        + 'Make sure you are using a valid antenna code for your user '
                        + 'or the transmission will be lost in space.\n\n'
                        + 'Usage: ' + argv[0] + ' &lt;antenna access code&gt;\n');
                }
                forthExec('send-photo-command', argv, cb);
            },
            photoview: function(argv, cb) {
                if (shouldHelp(argv, 1)) {
                    return cb('Photo viewer\nUsage: ' + argv[0] + ' &lt;filename&gt; \n');
                }
                PhotoViewer.load(argv[1]);
                return cb('Loading...\n');
            },
            test: function(argv, cb) {
                forthExec('test', argv, cb);
            },
            status: function(argv, cb) {
                forthExec('status', argv, cb);
            }
        };
    return {
        usr: username, pwd: password,
        exec: function(cmd, cb) {
            if (!cmd.length) { return cb(''); }
            var argv = cmd.split(/\s+/);
            if (bin[argv[0]]) {
                return bin[argv[0]](argv, cb);
            }
            return fail(cmd, cb);
        }
    };
}());
