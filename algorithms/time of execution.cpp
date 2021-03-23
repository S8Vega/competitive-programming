clock_t start, end;
start = clock();
// code
end = clock();
cout << double(end - start) / CLOCKS_PER_SEC << endl;