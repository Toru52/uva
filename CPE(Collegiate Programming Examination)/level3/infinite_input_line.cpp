while (scanf("%d", &x) == 1 && x) 
			while (scanf("%d%c", &y, &c) == 2) {
				graph[x][y] = 1,graph[y][x] = 1;
				if (c == '\n')	break;
			}