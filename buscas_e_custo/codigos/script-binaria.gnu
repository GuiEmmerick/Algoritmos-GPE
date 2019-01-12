set title "Binaria"
set xlabel "Tamanho do vetor"
set ylabel "Iteracoes"
f(x) = a*log(x*b) + c
set nokey
set grid
set term post eps enhanced color
set out 'binaria.eps'
fit f(x) "binaria.txt" via a,b,c
plot "binaria.txt", f(x)
