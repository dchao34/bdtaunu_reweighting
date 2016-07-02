#ifndef __FORMFACTORANALYZER_H__
#define __FORMFACTORANALYZER_H__

#include <vector>

#include <BPlnuDecayRate.h>
#include <BVlnuDecayRate.h>

#include "McDecayGraph.h"
#include "McDecayModeCurator.h"
#include "BSemiLepDict.h"
#include "BToDlnuMode.h"
#include "BToDslnuMode.h"
#include "BToDsslnuMode.h"
#include "CLNReweighter.h"
#include "LLSWReweighter.h"

class FormFactorAnalyzer {

  public:
    using Graph = McDecayGraph;
    using Vertex = McDecayGraphTraits::vertex_descriptor;
    using ConstIntPropertyMap = ConstMcDecayGraphIntPM;
    using ConstLorentzPropertyMap = ConstMcDecayGraphLorentzPM;

  public:

    FormFactorAnalyzer();
    FormFactorAnalyzer(bool ignore_fsr);
    ~FormFactorAnalyzer();

    void analyze(const Graph &g, const McDecayModeSummary &summary);

    double cln_weight() const { return cln_; }
    double llswb1_weight() const { return llswb1_; }
    double llswb2_weight() const { return llswb2_; }

    const std::vector<BToDlnuMode>& bdlnu() const { return bdlnu_; }
    const std::vector<BToDslnuMode>& bdslnu() const { return bdslnu_; }
    const std::vector<BToDsslnuMode>& bdsslnu() const { return bdsslnu_; }

  private:
    void clear_cache();

    void decay_lunds_from_vertices(
        std::vector<int>&, Vertex, const std::vector<Vertex>&);

    void collect_decay_modes(
        const Graph&, const McDecayModeSummary&);

    BToDlnuMode create_bdlnu_mode(Vertex, const std::vector<Vertex>&);
    BToDslnuMode create_bdslnu_mode(Vertex,
        const std::vector<Vertex>&, const McDecayModeSummary&);
    BToDsslnuMode create_bdsslnu_mode(Vertex, const std::vector<Vertex>&);

    void compute_ff_weights();


  private:

    BSemiLepDict bsl_dict_;
    CLNReweighter cln_reweighter_;
    LLSWReweighter llsw_reweighter_;
    bool ignore_fsr_;

    std::vector<BToDlnuMode> bdlnu_;
    std::vector<BToDslnuMode> bdslnu_;
    std::vector<BToDsslnuMode> bdsslnu_;

    double cln_;
    double llswb1_;
    double llswb2_;

    ConstIntPropertyMap lund_pm_;
    ConstLorentzPropertyMap lorentz_pm_;

};

#endif