#ifdef TEST

#include "CalcExprLexer.test.h"
#include <cassert>
#include "../main/Any/CalcExprLexer.h"
#include <vector>
#include "../main/Any/Enums.h"
#include <stdexcept>
#include <exception>

using std::vector;
using std::invalid_argument;
using std::exception;

namespace ii887522::Calculator
{
	static void testRun()
	{
		assert(CalcExprLexer{ }.run("0") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("1") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("2") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("3") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("4") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("5") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("6") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("7") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("8") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("9") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("0 0") == (vector{ Token::NUMBER, Token::NUMBER }));
		assert(CalcExprLexer{ }.run("0 1") == (vector{ Token::NUMBER, Token::NUMBER }));
		assert(CalcExprLexer{ }.run("-1") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("0.") == vector{ Token::NUMBER });
		assert(CalcExprLexer{ }.run("-") == vector{ Token::BINARY_OPERATOR });
		assert(CalcExprLexer{ }.run("0 =") == (vector{ Token::NUMBER, Token::EQUAL }));
		assert(CalcExprLexer{ }.run("0 +") == (vector{ Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(CalcExprLexer{ }.run("0 -") == (vector{ Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(CalcExprLexer{ }.run("0 x") == (vector{ Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(CalcExprLexer{ }.run("0 /") == (vector{ Token::NUMBER, Token::BINARY_OPERATOR }));
		assert(CalcExprLexer{ }.run("sqr(0)") == (vector{ Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET }));
		assert(CalcExprLexer{ }.run("sqr(sqrt(0))") == (vector{
			Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::UNARY_OPERATOR, Token::LEFT_BRACKET, Token::NUMBER, Token::RIGHT_BRACKET,
			Token::RIGHT_BRACKET
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
									CalcExprLexer{ }.run("sqr(0");
								}
								catch (const invalid_argument&)
								{
									try
									{
										CalcExprLexer{ }.run("sqr(1");
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
																						CalcExprLexer{ }.run("sqr(");
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
																								CalcExprLexer{ }.run("0)");
																							}
																							catch (const invalid_argument&)
																							{
																								try
																								{
																									CalcExprLexer{ }.run("sqr(0))");
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