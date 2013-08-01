#ifndef OXEN_RULES_HPP
#define OXEN_RULES_HPP

#include <string>

struct Rules
{
    float componentDamageProbability = 0.01;
    float structuralDamageProbability = 0.005;
    float crewKilledProbability = 0.001;
    float automationDamageProbability = 0.0005;

    void loadRuleSet(const std::string& ruleSetName);
};

#endif // OXEN_RULES_HPP
