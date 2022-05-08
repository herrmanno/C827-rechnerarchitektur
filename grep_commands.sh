cat $1 | tr '[:space:]' '[\n*]'|sort|grep -v '^[@"$(%.0-9]' |grep -v '^\s*$' |grep -v 'fib' |uniq -c
