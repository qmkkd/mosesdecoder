#pragma once
#include <string>
#include "StatelessFeatureFunction.h"
#include "moses/Word.h"

namespace Moses
{

// -inf if left-most or right-most non-term is over a set span
class MaxSpanFreeNonTermSource : public StatelessFeatureFunction
{
public:
	MaxSpanFreeNonTermSource(const std::string &line);

	  virtual bool IsUseable(const FactorMask &mask) const
	  { return true; }

	  virtual void Evaluate(const Phrase &source
							, const TargetPhrase &targetPhrase
							, ScoreComponentCollection &scoreBreakdown
							, ScoreComponentCollection &estimatedFutureScore) const;

	  virtual void Evaluate(const InputType &input
	                         , const InputPath &inputPath
	                         , const TargetPhrase &targetPhrase
	                         , const StackVec *stackVec
	                         , ScoreComponentCollection &scoreBreakdown
	                         , ScoreComponentCollection *estimatedFutureScore = NULL) const;

	  virtual void Evaluate(const Hypothesis& hypo,
	                        ScoreComponentCollection* accumulator) const
	  {}

	  virtual void EvaluateChart(const ChartHypothesis &hypo,
	                             ScoreComponentCollection* accumulator) const
	  {}

	  void SetParameter(const std::string& key, const std::string& value);
	  std::vector<float> DefaultWeights() const;

protected:
  int m_maxSpan;
  std::string m_glueTargetLHSStr;
  Word m_glueTargetLHS;
};

}
