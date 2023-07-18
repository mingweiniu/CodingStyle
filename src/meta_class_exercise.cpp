namespace meta {
	//
	// meta programming exercise
	//

	// void type
	struct VoidType {};

	// basic type
	template <typename ...Ts>
	struct BasicType {  };

	// bool type
	template <typename ...Ts>
	struct BoolType : BasicType<Ts...> { using res = VoidType; };
	struct TrueType : BoolType<> { constexpr static auto value = true; };
	struct FalseType : BoolType<> { constexpr static auto value = false; };

	//
	// Create a Container (List of Types)
	//
	template <typename ...Ts> struct List;

	template<>
	struct List<>
	{
		using res = BasicType<>;
		static constexpr const int size = 0;
	};

	template <typename T, typename ...Us>
	struct List<T, Us...> :List<Us...>
	{
		using res = BasicType<T, Us...>;
		static constexpr const int size = List<Us...>::size + 1;
	};

	template <typename T, typename U>
	using Pair = List<T, U>;

	//
	// Define Swap
	//

	// swap(A, B)
	template <typename ...Ts>
	struct Swap;
	
	template <typename L, typename R>
	struct Swap<L, R> { using res = Pair<R, L>; };
	
	template <typename L, typename R>
	struct Swap<Pair<L, R>> { using res = Pair<R, L>; };
	
	//
	// ternary operator
	//		
	template <typename Condition, typename T_Res, typename F_Res>
	struct TernaryOperator { 
		// default return false
		using res = F_Res; 
	};
	
	template <typename T_Res, typename F_Res>
	struct TernaryOperator<TrueType, T_Res, F_Res> { using res = T_Res; };	


	//
	// is same
	//
	template <typename T, typename U>
	struct IsSame { 
		// default return false
		using res = FalseType; 
	};
	
	template <typename T>
	struct IsSame<T, T> { using res = TrueType; };	



	//
	// list algorithm
	//

	// ceate a list
	template <typename ...Ts> 
	struct MakeList { using res = List<Ts...>; };
	
	// merge
	template<typename ...Lists> 
	struct Merge;
	
	template<typename... Ts, typename ...Us>
	struct Merge <List<Ts...>, List<Us...> > { using res = List<Ts..., Us...>; };
	
	template<typename... Ts, typename U>
	struct Merge <List<Ts...>, U> { using res = List<Ts..., U>; };
	
	template<typename... Ts, typename U>
	struct Merge <U, List<Ts...>> { using res = List<U, Ts...>; };
		

	// front(List)
	template<typename List> 
	struct Front { using res = VoidType; };	

	template <typename T, typename ...Us>
	struct Front<List<T, Us...>> { using res = T; };	
	
	// pop(List)
	template<typename List>
	struct Pop;

	template<>
	struct Pop<List<>> { using res = List<>; };

	template <typename T, typename ...Us>
	struct Pop<List<T, Us...>> { using res = List<Us...>; };
	

	// implement of find list
	template<typename ...Ts> 
	struct pFind_imp { using res = FalseType; };
	
	template<typename T>
	struct pFind_imp<T> { using res = FalseType; };
	
	template<typename ...Ts, typename U> // variadic must be at the last position
	struct pFind_imp<U, U, Ts...> { 
		using res = TrueType; 
		static constexpr const int remain_size = List<U, Ts...>::size;
	};
	
	template<typename T, typename U, typename ...Vs>
	struct pFind_imp<T, U, Vs...> : pFind_imp<T, Vs...> 
	{};
	
	
	// find(List, type)
	template<typename List, typename T>
	struct IsFind;

	template<typename T, typename ...Us>
	struct IsFind<List<Us...>, T> : pFind_imp<T, Us...> 
	{};
	
	// find pose
	template<typename List, typename T>
	constexpr inline int FindPose()
	{
		using FindResult = IsFind<List, T>;
		if constexpr (FindResult::res::value)
		{
			return List::size - FindResult::remain_size;
		}
		
		return -1;
	}


}

int main()
{
	using namespace meta;

	using swap_float_double = Swap<float, double>::res; // BasicType<double, float>

	using ternary_true_float_double = TernaryOperator<TrueType, float, double>::res; // float
	using ternary_false_float_double = TernaryOperator<FalseType, float, double>::res; // double


	using is_same_float_double = IsSame<float, double>::res; // false
	using is_same_float_float = IsSame<float, float>::res; // true


	using my_listA = MakeList<float, float>::res; // List<float, float>
	using Merge_listA_double = Merge<my_listA, double>::res; // List<float, float, double>
	using new_list = Merge<List<int, int>, Merge_listA_double>::res; // List<int, int, float, float, double>


	using first_front = Front<new_list>::res; // float
	using pop_list1 = Pop<new_list>::res; // List<int, float, float, double>
	using pop_list2 = Pop<pop_list1>::res; // List<float, float, double>
	using pop_list3 = Pop<pop_list2>::res; // List<float, double>
	using pop_list4 = Pop<pop_list3>::res; // List<double>
	using pop_list5 = Pop<pop_list4>::res; // List<>
	using pop_list6 = Pop<pop_list5>::res; // List<>
	
	using font_list3 = Front<pop_list3>::res;
	using font_list6 = Front<pop_list6>::res;

	using is_find_bool_in_list = IsFind<new_list, bool>::res; //false
	using is_find_int_in_list = IsFind<new_list, int>::res; //true



	constexpr BasicType<> a = {};
	constexpr auto new_list_size = new_list::size; // 5
	constexpr auto pop_list6_size = pop_list6::size;

	constexpr auto find_int_pose = FindPose<new_list, int>();  // 0
	constexpr auto find_float_pose = FindPose<new_list, float>(); // 2
	constexpr auto find_double_pose = FindPose<new_list, double>();  //4	
	constexpr auto find_bool_pose = FindPose<new_list, bool>();  // -1

}
