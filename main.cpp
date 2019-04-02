#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "wcnn.h"
//测试卷积
void testCov(){
    CDataBlob inputData(1,4,5,5);
    inputData.data_float={{{{-5.5206e-01, -1.3327e+00, -9.6631e-01,  1.3685e+00, -4.1081e-01},
                            { 6.5883e-01,  1.7206e-01, -2.6127e-01,  1.5243e+00, -1.0075e+00},
                            { 1.1112e+00,  1.2595e+00, -1.6282e-01, -5.1200e-01, -1.7343e-01},
                            {-2.7124e-01,  1.3276e+00,  6.3410e-01,  1.3554e+00, -7.6201e-02},
                            {-1.9538e-03,  6.9230e-01,  1.2193e+00,  7.7638e-01,  8.5696e-01}},

                           {{-7.8446e-02,  7.2267e-01, -7.0697e-01, -8.2278e-01,  2.8154e-01},
                            {-2.2324e+00,  1.7611e-01, -9.4444e-01, -1.2315e+00,  3.7315e-01},
                            {-1.7369e+00,  6.2123e-01, -1.3330e+00, -7.9458e-01, -2.4785e-01},
                            {-4.8617e-01,  4.4016e-01, -2.1703e+00,  2.5121e-01, -6.2328e-02},
                            { 1.3065e+00, -2.0849e+00, -5.1301e-02, -9.3929e-01,  1.0895e+00}},

                           {{ 2.7805e-01, -4.1970e-01,  2.4863e+00, -2.9015e+00,  8.1118e-01},
                            { 1.0164e+00,  2.4565e-01,  1.3769e-01, -2.6734e-01,  4.7465e-01},
                            { 1.3503e+00,  1.5392e+00,  1.3353e+00, -8.0135e-01, -4.4794e-01},
                            {-1.5889e-01,  3.1288e-01,  1.1469e+00,  1.7620e-01, -1.2321e-02},
                            { 3.1716e-01,  5.9338e-01, -1.3817e+00,  2.6376e-01, -1.0761e+00}},

                           {{ 4.8384e-01, -1.3983e-01,  1.9736e+00, -1.7423e-01, -2.5046e-01},
                            { 1.6751e-01,  9.8185e-01, -2.1264e-01,  4.1853e-01, -1.5432e-01},
                            {-5.5043e-01, -2.8385e+00,  1.5255e-01, -6.9478e-01, -1.8211e+00},
                            { 1.9278e+00,  7.7455e-01,  7.3442e-01, -1.4730e+00, -8.5779e-01},
                            { 1.1854e-01,  1.4436e+00, -7.0385e-01,  1.3248e+00, -2.5469e+00}}}};

   CDataBlob weigth(4,2,3,3);
   weigth.data_float={{{{ 0.2939, -0.1639, -0.9099},
                        {-0.0662,  0.6573,  1.0217},
                        { 0.5235, -1.1140,  0.3504}},

                       {{-1.2583,  0.4282,  0.0435},
                        { 1.3338, -0.9523, -0.3468},
                        {-0.5925,  0.1982, -0.1812}}},


                      {{{ 2.0044, -0.2663, -0.0913},
                        { 0.3553, -0.6623, -0.4073},
                        {-1.0647, -0.6308, -0.3822}},

                       {{ 1.8922, -1.2378,  0.7259},
                        {-0.5025, -1.0041,  2.5327},
                        { 0.2835,  0.4321, -0.8296}}},


                      {{{-2.4078, -0.0111,  0.0992},
                        {-0.3758, -1.5001, -0.5062},
                        {-0.8001,  1.8466,  0.7307}},

                       {{-1.0821, -0.6087, -0.9051},
                        { 1.4373,  2.0768, -0.9805},
                        { 0.3215, -0.0536,  1.4021}}},


                      {{{-0.2429, -0.7302,  0.3869},
                        { 0.1547,  2.4416, -1.8130},
                        {-1.2256, -0.1704, -0.9374}},

                       {{ 0.0250,  0.7704, -0.8758},
                        { 1.1362,  1.0234, -0.7100},
                        {-0.6157, -1.7720,  0.2216}}}};
    Cbias bias={ 0.6045,  0.4045, -1.5431,  0.3637};
    covFilters  filters;
    filters.padding_padH=2;
    filters.padding_padW=2;
    filters.dilation_dH=2;
    filters.dilation_dW=2;
    filters.stride_sH=2;
    filters.stride_sW=2;
    filters.groups=2;
    CDataBlob outputData(1,4,3,3);
    Conv2d(&inputData,&weigth,&bias,&filters, &outputData);
    qDebug()<<outputData.data_float;
}

//template <typename Tp>
//using myVec = vector<Tp>;

int main(int argc, char *argv[])
{
	vector<double> kernel{ 1.0, 1.0 };
	vector<double> vec{0.8, 0.364};
	vector<double> mult;
	std::transform(kernel.begin(), kernel.end(), vec.begin(), std::back_inserter(mult), std::multiplies<double>());
	const std::vector<double> v{ 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0 };

	auto biggest = std::max_element(std::cbegin(v), std::cend(v));
	std::cout << "aa" << typeid(biggest).name() << std::endl;
	auto au = 9 / 2;
	CDataBlob input(1, 2, 8, 8);
	input.data_float = { { 
						{ { 0.7806, 0.1144, 0.2359, 0.3974, 0.5226, 0.1122, 0.5217, 0.7111 },
						{ 0.9819, 0.2203, 0.1389, 0.8409, 0.7898, 0.9231, 0.5383, 0.2672 },
						{ 0.1799, 0.0879, 0.5555, 0.7010, 0.8822, 0.9760, 0.5518, 0.9074 },
						{ 0.6279, 0.2893, 0.5922, 0.8142, 0.1963, 0.8402, 0.0837, 0.0335 },
						{ 0.7927, 0.5866, 0.1312, 0.0621, 0.4014, 0.6445, 0.0426, 0.4867 },
						{ 0.8103, 0.6106, 0.1620, 0.6706, 0.3666, 0.8752, 0.4540, 0.3589 },
						{ 0.1180, 0.4366, 0.3363, 0.7593, 0.9605, 0.0609, 0.2817, 0.8587 },
						{ 0.6828, 0.0024, 0.4131, 0.7371, 0.5852, 0.3887, 0.3838, 0.0428 } },

						{ { 0.7663, 0.9236, 0.5231, 0.8728, 0.2985, 0.7798, 0.8019, 0.8220 },
						{ 0.3009, 0.1610, 0.4365, 0.2582, 0.9125, 0.8900, 0.7145, 0.3426 },
						{ 0.7688, 0.7401, 0.8362, 0.8875, 0.1657, 0.8641, 0.2714, 0.9904 },
						{ 0.5041, 0.6628, 0.2526, 0.7577, 0.7930, 0.2275, 0.0978, 0.6620 },
						{ 0.4815, 0.8503, 0.5579, 0.3074, 0.6134, 0.8671, 0.1788, 0.7941 },
						{ 0.8077, 0.9856, 0.8386, 0.8819, 0.9215, 0.3613, 0.6352, 0.6687 },
						{ 0.2495, 0.6221, 0.8385, 0.0518, 0.1051, 0.9036, 0.3022, 0.0488 },
						{ 0.0917, 0.0643, 0.2964, 0.9249, 0.6331, 0.6122, 0.7403, 0.1357 } } 
						} };
	
	maxFilters maxfilter(2, 2, 3, 3, 0, 0, 2, 2, false, true);
	CDataBlob output;
	bool flag = MaxPool2d(&input, &maxfilter, &output);
	qDebug() << "output: " << output.data_float;
    QCoreApplication a(argc, argv);
    testCov();
    return a.exec();
}
