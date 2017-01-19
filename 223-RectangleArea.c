int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int buttomX = (A - E > 0) ? E : A;
		int topY = (D - H > 0) ? D : H;
		int topX = (G - C > 0) ? G : C;
		int surroundRect = (topY - buttomY) * (topX - buttomX);
		int diffTopY = (D - H > 0)?(D - H):(H - D);
		int diffButtomY = (B - F > 0)?(B - F):(F - B);
		int diffTopX = (G - C > 0)?(G - C):(C - G);
		int diffButtomX = (E - A > 0)?(E - A):(A - E);
		int emptyRect = 0;
		if ((B - F) * (A - E) >= 0) {
			emptyRect = diffTopY * diffButtomX + diffTopX * diffButtomY;
		} else {
			emptyRect = diffTopX * diffTopY + diffButtomX * diffButtomY;
		}
		return surroundRect - emptyRect;
}
