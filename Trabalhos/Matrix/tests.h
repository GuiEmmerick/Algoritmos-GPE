TEST(Matrix, operador_colchetes){
	Matrix mat(3,3);

	mat[0][0]=1;
	ASSERT_EQ(mat[0][0],1);
}

TEST(Matrix, soma){
	Matrix mat(1,1);
	Matrix mat1(1,1);
	mat[0][0] =1;
	mat1[0][0] =1;
	Matrix mat2 (mat+mat1);
	ASSERT_EQ(mat2[0][0], 2);
}

TEST(Matrix, soma_exception){
	Matrix mat(3,3);
	Matrix mat1(6,7);

	ASSERT_THROW(mat+mat1, std::invalid_argument);
}

TEST(Matrix, sub){
	Matrix mat(1,1);
	Matrix mat1(1,1);
	mat[0][0] =1;
	mat1[0][0] =1;
	Matrix mat2 (mat-mat1);
	ASSERT_EQ(mat2[0][0], 0);
}

TEST(Matrix, sub_exception){
	Matrix mat(3,3);
	Matrix mat1(6,7);

	ASSERT_THROW(mat-mat1, std::invalid_argument);
}

TEST(Matrix, tam_dif){
	Matrix mat(2,6);
	Matrix mat1(1,3);

	ASSERT_THROW((mat+mat1), std::invalid_argument);
}

TEST(Matrix, multiplicacao){
	Matrix mat(3,3);
	Matrix mat1(3,3);

	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			mat[i][j]=1;
			mat1[i][j]=1;
		}
	}
	Matrix mat2(mat*mat1);
	ASSERT_EQ(mat2[0][0],3);
}

TEST(Matrix, multiplicacao_exception){
	Matrix mat(3,3);
	Matrix mat1(6,7);

	ASSERT_THROW(mat*mat1, std::invalid_argument);

}

TEST(Matrix, operador_igual){
	Matrix mat(3,3);
	Matrix mat1(3,3);

	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			mat[i][j]=0;
			mat1[i][j]=1;
		}
	}
	mat = mat1;
	ASSERT_EQ(mat[0][0],1);
}


TEST(Matrix, construtor_copia){
	Matrix mat(3,3);

	for(int i=0; i<3;i++){
		for(int j=0; j<3;j++){
			mat[i][j]=0;
		}
	}
	Matrix mat1(mat);
	ASSERT_EQ(mat1[0][0],0);
}

TEST(Matrix, zero){
	Matrix mat(2,2);
	mat.preencher_zero();
	ASSERT_EQ(mat[0][0],0);
}



