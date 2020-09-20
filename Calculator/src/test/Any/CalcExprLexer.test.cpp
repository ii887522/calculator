#ifdef TEST

#include "CalcExprLexer.test.h"
#include <cassert>
#include "../../main/Any/CalcExprLexer.h"
#include <vector>
#include "../../main/Struct/Token.h"
#include <stdexcept>
#include <exception>
#include "../../main/Functions/comparison.h"

using std::vector;
using std::invalid_argument;
using std::exception;

namespace ii887522::Calculator
{
	static void testRun()
	{
		assert(equal(CalcExprLexer{ }.run("0"), vector{ Token{ Token::Type::NUMBER, "0" } }));
		assert(equal(CalcExprLexer{ }.run("1"), vector{ Token{ Token::Type::NUMBER, "1" } }));
		assert(equal(CalcExprLexer{ }.run("2"), vector{ Token{ Token::Type::NUMBER, "2" } }));
		assert(equal(CalcExprLexer{ }.run("3"), vector{ Token{ Token::Type::NUMBER, "3" } }));
		assert(equal(CalcExprLexer{ }.run("4"), vector{ Token{ Token::Type::NUMBER, "4" } }));
		assert(equal(CalcExprLexer{ }.run("5"), vector{ Token{ Token::Type::NUMBER, "5" } }));
		assert(equal(CalcExprLexer{ }.run("6"), vector{ Token{ Token::Type::NUMBER, "6" } }));
		assert(equal(CalcExprLexer{ }.run("7"), vector{ Token{ Token::Type::NUMBER, "7" } }));
		assert(equal(CalcExprLexer{ }.run("8"), vector{ Token{ Token::Type::NUMBER, "8" } }));
		assert(equal(CalcExprLexer{ }.run("9"), vector{ Token{ Token::Type::NUMBER, "9" } }));
		assert(equal(CalcExprLexer{ }.run("19"), vector{ Token{ Token::Type::NUMBER, "19" } }));
		assert(equal(CalcExprLexer{ }.run("0 0"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::NUMBER, "0" } }));
		assert(equal(CalcExprLexer{ }.run("0 1"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::NUMBER, "1" } }));
		assert(equal(CalcExprLexer{ }.run("-1"), vector{ Token{ Token::Type::NUMBER, "-1" } }));
		assert(equal(CalcExprLexer{ }.run("0."), vector{ Token{ Token::Type::NUMBER, "0." } }));
		assert(equal(CalcExprLexer{ }.run("-"), vector{ Token{ Token::Type::BINARY_OPERATOR, "-" } }));
		assert(equal(CalcExprLexer{ }.run("0 ="), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::EQUAL } }));
		assert(equal(CalcExprLexer{ }.run("0 +"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::BINARY_OPERATOR, "+" } }));
		assert(equal(CalcExprLexer{ }.run("0 -"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::BINARY_OPERATOR, "-" } }));
		assert(equal(CalcExprLexer{ }.run("0 x"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::BINARY_OPERATOR, "x" } }));
		assert(equal(CalcExprLexer{ }.run("0 /"), vector{ Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::BINARY_OPERATOR, "/" } }));
		assert(equal(CalcExprLexer{ }.run("sqr(0)"), vector{
			Token{ Token::Type::UNARY_OPERATOR, "sqr" }, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER, "0" },
			Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(equal(CalcExprLexer{ }.run("sqr(sqrt(0))"), vector{
			Token{ Token::Type::UNARY_OPERATOR, "sqr"}, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::UNARY_OPERATOR, "sqrt" },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::RIGHT_BRACKET },
			Token{ Token::Type::RIGHT_BRACKET }
		}));
		assert(equal(CalcExprLexer{ }.run("sqr(sqrt(0)) +"), vector{
			Token{ Token::Type::UNARY_OPERATOR, "sqr"}, Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::UNARY_OPERATOR, "sqrt" },
			Token{ Token::Type::LEFT_BRACKET }, Token{ Token::Type::NUMBER, "0" }, Token{ Token::Type::RIGHT_BRACKET },
			Token{ Token::Type::RIGHT_BRACKET }, Token{ Token::Type::BINARY_OPERATOR, "+" }
		}));
		try
		{
			CalcExprLexer{ }.run("0 + ");
		}
		catch (const invalid_argument&)
		{
			try
			{
				CalcExprLexer{ }.run("0 ");
			}
			catch (const invalid_argument&)
			{
				try
				{
					CalcExprLexer{ }.run("- ");
				}
				catch (const invalid_argument&)
				{
					try
					{
						CalcExprLexer{ }.run("");
					}
					catch (const invalid_argument&)
					{
						try
						{
							CalcExprLexer{ }.run("00");
						}
						catch (const invalid_argument&)
						{
							try
							{
								CalcExprLexer{ }.run("-0");
							}
							catch (const invalid_argument&)
							{
								try
								{
									CalcExprLexer{ }.run(".");
								}
								catch (const invalid_argument&)
								{
									try
									{
										CalcExprLexer{ }.run("0-");
									}
									catch (const invalid_argument&)
									{
										try
										{
											CalcExprLexer{ }.run("0+");
										}
										catch (const invalid_argument&)
										{
											try
											{
												CalcExprLexer{ }.run("s");
											}
											catch (const invalid_argument&)
											{
												try
												{
													CalcExprLexer{ }.run("0s");
												}
												catch (const invalid_argument&)
												{
													try
													{
														CalcExprLexer{ }.run("sq");
													}
													catch (const invalid_argument&)
													{
														try
														{
															CalcExprLexer{ }.run("0q");
														}
														catch (const invalid_argument&)
														{
															try
															{
																CalcExprLexer{ }.run("sqr");
															}
															catch (const invalid_argument&)
															{
																try
																{
																	CalcExprLexer{ }.run("0r");
																}
																catch (const invalid_argument&)
																{
																	try
																	{
																		CalcExprLexer{ }.run("sqrt");
																	}
																	catch (const invalid_argument&)
																	{
																		try
																		{
																			CalcExprLexer{ }.run("0t");
																		}
																		catch (const invalid_argument&)
																		{
																			try
																			{
																				CalcExprLexer{ }.run("0(");
																			}
																			catch (const invalid_argument&)
																			{
																				try
																				{
																					CalcExprLexer{ }.run(")");
																				}
																				catch (const invalid_argument&)
																				{
																					try
																					{
																						CalcExprLexer{ }.run("a");
																					}
																					catch (const invalid_argument&)
																					{
																						return;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		throw exception{ };
	}

	void testCalcExprLexer()
	{
		testRun();
	}
}

#endif