TEST(List, is_empty){
	List list;
	ASSERT_TRUE(list.IsEmpty());
}

TEST(List, empty_list){
	List list;
	ASSERT_THROW(list.GetValue(), std::invalid_argument);
}

TEST(List, GetValue){
	List list;
	list.AddNodeNext(2);

	ASSERT_EQ(list.GetValue(), 2);
}

TEST(List, AddNodePrevious){
	List list;
	list.AddNodePrevious(1);
	list.AddNodePrevious(2);
	list.AddNodePrevious(3);
	list.AddNodePrevious(4);

	ASSERT_EQ(list.GetValue(), 1);

}

TEST(List, GetValueNext){
	List list;
	list.AddNodeNext(2);
	list.AddNodeNext(6);
	ASSERT_EQ(list.GetValueNext(),6);
}

TEST(List, GetValuePrevious){
	List list;
	list.AddNodeNext(2);
	list.AddNodePrevious(6);
	list.AddNodePrevious(8);
	ASSERT_EQ(list.GetValuePrevious(),8);
}

TEST(list, ApagaPositionNextErro){
	List list;

	ASSERT_THROW(list.ApagaPositionPositionNext(), std::invalid_argument);
}

TEST(list, ApagaPositionNext){
	List list;
	list.AddNodeNext(2);
	list.AddNodeNext(6);
	list.AddNodeNext(8);
	list.ApagaPositionPositionNext();
	ASSERT_EQ(list.GetValue(), 8);
}

TEST(list, ApagaPositionPreviousErro){
	List list;

	ASSERT_THROW(list.ApagaPositionPositionPrevious(), std::invalid_argument);
}

TEST(list, ApagaPositionPrevious){
	List list;
	list.AddNodeNext(2);
	list.AddNodeNext(6);
	list.AddNodeNext(8);
	list.ApagaPositionPositionPrevious();
	ASSERT_EQ(list.GetValue(), 6);
}

TEST(List, ApontaNextNodeErro){
	List list;

	ASSERT_THROW(list.ApontaNextNode(), std::invalid_argument);
}

TEST(List, ApontaNextNode){
	List list;
	list.AddNodePrevious(2);
	list.AddNodePrevious(6);
	list.ApontaNextNode();
	ASSERT_EQ(list.GetValue(), 6);
}

TEST(List, ApontaPreviousNode){
	List list;
	list.AddNodePrevious(2);
	list.AddNodePrevious(6);
	list.AddNodePrevious(8);
	list.ApontaPreviousNode();
	ASSERT_EQ(list.GetValue(), 8);
}

TEST(List, ApontaPreviusNodeErro){
	List list;

	ASSERT_THROW(list.ApontaPreviousNode(), std::invalid_argument);
}

TEST(List, BuscaValor){
	List list;
	list.AddNodePrevious(1);
	list.AddNodePrevious(2);
	list.AddNodePrevious(3);
	list.AddNodePrevious(4);

	ASSERT_TRUE(list.BuscaValor(3));
}

TEST(List, Destrutor){
	List list;
	list.AddNodePrevious(1);
	list.AddNodePrevious(2);
	list.AddNodePrevious(3);
	list.AddNodePrevious(4);
	list.ApagaPositionPositionNext();
	list.ApagaPositionPositionNext();
	list.ApagaPositionPositionNext();
	list.ApagaPositionPositionNext();

	ASSERT_TRUE(list.IsEmpty());
}
