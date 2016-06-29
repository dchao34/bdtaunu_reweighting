//*****************************************************************
//
//   This class should be used in this fashion:
//
//   XSLKin pseudoScalarKin(BLab,LepLab,XuLab);
//   double q = pseudoScalarKin.q2();
//
//   XSLKin vectorKin(BLab,LepLab,XuLab,XuDLab);
//   double cosTheta_l = vectorKin.ctl();
//
//   The 4-Vectors given has input should be in the LAB frame.
//   It is left to the user of the class to decide wheter to use the measured mass or the PDG mass.
//
//   Creation: David Cote, Universite de Montreal, 12/11/03
//   History:  DC, 11/23/04: Merge XSLKin, XSLPseudoScalarKin and XSLVectorKin into one single (and simpler) class: XSLKin
//
//   Class created from an original code by Arthur E. Snyder : LblMixRepo/DStarLNuYFrameAve.cc .hh (Thanks! :-) )
//   Complete documentation available in BAD #809


#ifndef _XSLKIN_H_
#define _XSLKIN_H_

#include <CLHEP/Vector/LorentzVector.h>

class XSLKin {

  public:

    // constructors
    XSLKin( XSLKin* Kin );
    XSLKin(CLHEP::HepLorentzVector BLab, CLHEP::HepLorentzVector LepLab, CLHEP::HepLorentzVector XuLab);
    XSLKin(CLHEP::HepLorentzVector BLab, CLHEP::HepLorentzVector LepLab, CLHEP::HepLorentzVector XuLab, CLHEP::HepLorentzVector XuDaughterLab);

    // copy-control
    ~XSLKin(){};

    // accessors for kinetmatic variables
    double z();
    double w(){ return _w; }
    double q2(){ return _q2; }
    double ctl(){ return _ctl; }
    double theta_l(){ return _theta_l; }
    double ctv(){ return _ctv; }
    double theta_v(){ return _theta_v; }
    double chi(){ return _chi; }

    //other... (mainly useful for copy constructors):
    bool isVector(){ return _isVector; }
    CLHEP::HepLorentzVector XuLab(){ return _XuLab; }
    CLHEP::HepLorentzVector XuDLab(){ return _XuDaugLab; }
    CLHEP::HepLorentzVector LepLab(){ return _LepLab; }
    CLHEP::HepLorentzVector BLab(){ return _BLab; };

  private:
    void Init();
    void Compute();   

    //Computed by the class:
    double _ctl;
    double _theta_l;
    double _q2;
    double _w;
    double _ctv;
    double _chi;
    double _theta_v;

    //From the constructor:
    CLHEP::HepLorentzVector _BLab;
    CLHEP::HepLorentzVector _LepLab;
    CLHEP::HepLorentzVector _XuLab;
    CLHEP::HepLorentzVector _XuDaugLab;

    bool _isVector;
    
};

#endif


