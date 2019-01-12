set title "Ingenua"
set xlabel "Tamanho do vetor"
set ylabel "Iteracoes"
f(x) = a*x + b
set nokey
set grid
set term post eps enhanced color
set out 'ingenua.eps'
fit f(x) "ingenua.txt" via a,b
plot "ingenua.txt", f(x)
