/* ===== 23e2eb880 ui.hotkey_listener:115 ===== */
/* ghidra_name=FUN_23e2eb880 entry=23e2eb880 size=17614 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2eb880(longlong param_1,undefined8 param_2,longlong *param_3)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  longlong *plVar18;
  longlong lVar19;
  undefined8 uVar20;
  code *pcVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  code *pcVar25;
  code *pcVar26;
  undefined1 auVar27 [8];
  undefined4 uVar28;
  int iVar29;
  longlong *plStack_200;
  longlong *plStack_1f8;
  longlong *plStack_1f0;
  longlong *plStack_1e8;
  longlong *plStack_1e0;
  longlong *plStack_1d8;
  undefined1 auStack_1a8 [16];
  code *apcStack_198 [2];
  code *pcStack_188;
  code *pcStack_180;
  code *pcStack_178;
  code *pcStack_168;
  code *pcStack_160;
  code *pcStack_158;
  undefined8 uStack_148;
  undefined8 uStack_140;
  longlong *plStack_138;
  code *pcStack_128;
  code *pcStack_120;
  code *pcStack_118;
  code *pcStack_108;
  code *pcStack_100;
  code *pcStack_f8;
  code *pcStack_e8;
  code *pcStack_e0;
  code *pcStack_d8;
  undefined1 auStack_c8 [16];
  code *apcStack_b8 [2];
  undefined1 auStack_a8 [8];
  code *pcStack_a0;
  code *apcStack_98 [2];
  code *pcStack_88;
  code *pcStack_80;
  code *pcStack_78;
  
  pcVar21 = DAT_23ed6a4e0;
  lVar17 = *param_3;
  if (DAT_23ed6a4e0 == (code *)0x0) {
    pcVar21 = (code *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    pcVar23 = *(code **)DAT_23ed6a4e0;
    *(longlong *)DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = pcVar23;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar23 = _PyRuntime_exref;
  plVar11 = _DAT_23eeb00f0;
  *(longlong *)(pcVar21 + 0x10) = lVar17;
  lVar19 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar21 + -8);
  puVar3 = *(undefined8 **)(lVar19 + 8);
  *puVar3 = pcVar21 + -0x10;
  *(longlong *)(pcVar21 + -0x10) = lVar19;
  *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(code **)(lVar19 + 8) = pcVar21 + -0x10;
  apcStack_98[0] = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  pcStack_a0 = (code *)0x0;
  if (plVar11 == (longlong *)0x0) {
LAB_23e2eb95d:
    plVar11 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb00e8,DAT_23eeb0170,0x40);
    lVar17 = *(longlong *)(pcVar21 + 0x10);
    _DAT_23eeb00f0 = plVar11;
  }
  else {
    lVar19 = *plVar11;
    if (1 < lVar19) {
      *plVar11 = lVar19 + -1;
      goto LAB_23e2eb95d;
    }
    if (plVar11[2] != 0) {
      *plVar11 = lVar19 + -1;
      if (lVar19 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2eb95d;
    }
  }
  lVar19 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(lVar19 + 8);
  plVar11[0xf] = lVar2;
  *(longlong **)(lVar19 + 8) = plVar11 + 9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar11[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar11[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar11 = *plVar11 + 1;
  *(undefined4 *)(plVar11 + 8) = 0;
  plStack_1d8 = (longlong *)0x0;
  plStack_1e0 = (longlong *)0x0;
  plStack_1e8 = (longlong *)0x0;
  plStack_1f0 = (longlong *)0x0;
  plStack_1f8 = (longlong *)0x0;
  plStack_200 = (longlong *)0x0;
LAB_23e2eba21:
  if (lVar17 == 0) {
    pcStack_a0 = (code *)PyUnicode_FromFormat
                                   ("cannot access local variable \'%U\' where it is not associated with a value"
                                    ,_DAT_23eead1d8);
    auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
    *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
    apcStack_98[0] = (code *)0x0;
    if (auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
  }
  else {
    plVar12 = (longlong *)FUN_23e8bc2f0(lVar17,DAT_23eead0c0);
    if (plVar12 != (longlong *)0x0) {
      iVar9 = FUN_23a35f020();
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if (iVar9 == -1) goto LAB_23e2ed840;
      if (iVar9 == 0) {
        lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar11 = *(longlong **)(lVar17 + 0x28);
        plVar12 = (longlong *)plVar11[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
        *(undefined4 *)(plVar11 + 8) = 0xffffffff;
        if (plVar12 != (longlong *)0x0) {
          plVar11[2] = 0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
          }
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        pcVar23 = _Py_NoneStruct_exref;
        plVar11[0xf] = 0;
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
        if (*(longlong *)pcVar21 == 0) {
          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
        }
        if ((plStack_200 != (longlong *)0x0) &&
           (lVar17 = *plStack_200, *plStack_200 = lVar17 + -1, lVar17 + -1 == 0)) {
          (**(code **)(plStack_200[1] + 0x30))(plStack_200);
        }
        if ((plStack_1f8 != (longlong *)0x0) &&
           (lVar17 = *plStack_1f8, *plStack_1f8 = lVar17 + -1, lVar17 + -1 == 0)) {
          (**(code **)(plStack_1f8[1] + 0x30))(plStack_1f8);
        }
        if ((plStack_1f0 != (longlong *)0x0) &&
           (lVar17 = *plStack_1f0, *plStack_1f0 = lVar17 + -1, lVar17 + -1 == 0)) {
          (**(code **)(plStack_1f0[1] + 0x30))(plStack_1f0);
        }
        if ((plStack_1e8 != (longlong *)0x0) &&
           (lVar17 = *plStack_1e8, *plStack_1e8 = lVar17 + -1, lVar17 + -1 == 0)) {
          (**(code **)(plStack_1e8[1] + 0x30))(plStack_1e8);
        }
        if ((plStack_1e0 != (longlong *)0x0) &&
           (lVar17 = *plStack_1e0, *plStack_1e0 = lVar17 + -1, lVar17 + -1 == 0)) {
          (**(code **)(plStack_1e0[1] + 0x30))(plStack_1e0);
        }
        if (plStack_1d8 == (longlong *)0x0) {
          return pcVar23;
        }
        lVar17 = *plStack_1d8;
        *plStack_1d8 = lVar17 + -1;
        if (lVar17 + -1 != 0) {
          return pcVar23;
        }
        (**(code **)(plStack_1d8[1] + 0x30))(plStack_1d8);
        return pcVar23;
      }
      if (*(longlong *)(pcVar21 + 0x10) == 0) goto LAB_23e2ecf18;
      plVar12 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0d8);
      if (plVar12 == (longlong *)0x0) {
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ec533:
        iVar9 = 0x77;
        pcVar26 = _Py_NoneStruct_exref;
LAB_23e2ec2b0:
        do {
          pcStack_a0 = pcVar24;
          auStack_a8 = auVar27;
          apcStack_98[0] = pcVar23;
          pcVar23 = apcStack_98[0];
          auStack_1a8._8_8_ = pcStack_a0;
          auStack_1a8._0_8_ = auStack_a8;
          apcStack_98[0] = (code *)0x0;
          plVar12 = *(longlong **)(param_1 + 0x138);
          auStack_a8 = (undefined1  [8])0x0;
          pcStack_a0 = (code *)0x0;
          apcStack_198[0] = pcVar23;
          if (plVar12 != (longlong *)0x0) {
            *plVar12 = *plVar12 + 1;
          }
          pcVar24 = DAT_23ed6a4f8;
          if (pcVar23 == (code *)0x0) {
            if (iVar9 == 0) {
              iVar9 = (int)plVar11[5];
            }
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              pcVar23 = apcStack_198[0];
            }
            else {
              pcVar23 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar23;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              pcVar23 = (code *)0x0;
            }
            pcVar22 = _PyRuntime_exref;
            *(longlong *)(pcVar24 + 0x10) = 0;
            *(longlong **)(pcVar24 + 0x18) = plVar11;
            *plVar11 = *plVar11 + 1;
            lVar17 = *(longlong *)(pcVar22 + 0x1f8);
            *(int *)(pcVar24 + 0x24) = iVar9;
            lVar17 = *(longlong *)(lVar17 + 0x10);
            *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
            lVar17 = *(longlong *)(lVar17 + 0x2e8);
            lVar19 = *(longlong *)(pcVar24 + -8);
            puVar3 = *(undefined8 **)(lVar17 + 8);
            *puVar3 = pcVar24 + -0x10;
            *(longlong *)(pcVar24 + -0x10) = lVar17;
            *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
            *(code **)(lVar17 + 8) = pcVar24 + -0x10;
            pcVar22 = pcVar24;
            if ((pcVar23 != (code *)0x0) &&
               (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
            }
          }
          else {
            pcVar22 = apcStack_198[0];
            if (iVar9 != 0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar22 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar22;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar22 = _PyRuntime_exref;
              *(longlong **)(pcVar24 + 0x18) = plVar11;
              *plVar11 = *plVar11 + 1;
              lVar17 = *(longlong *)(pcVar22 + 0x1f8);
              *(int *)(pcVar24 + 0x24) = iVar9;
              *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
              lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
              lVar19 = *(longlong *)(pcVar24 + -8);
              puVar3 = *(undefined8 **)(lVar17 + 8);
              *puVar3 = pcVar24 + -0x10;
              *(longlong *)(pcVar24 + -0x10) = lVar17;
              *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
              *(code **)(lVar17 + 8) = pcVar24 + -0x10;
              *(code **)(pcVar24 + 0x10) = pcVar23;
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              pcVar22 = pcVar24;
              if ((apcStack_198[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_198[0] = *(longlong *)apcStack_198[0] + -1,
                 *(longlong *)apcStack_198[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_198[0] + 8) + 0x30))();
              }
            }
          }
          apcStack_198[0] = pcVar22;
          if (((code *)auStack_1a8._0_8_ != pcVar26) && ((code *)auStack_1a8._0_8_ != (code *)0x0))
          {
            FUN_23e91b1b0(param_1,auStack_1a8,auStack_1a8 + 8,apcStack_198);
          }
          plVar13 = *(longlong **)(auStack_1a8._8_8_ + 0x28);
          if (apcStack_198[0] == pcVar26) {
            pcVar23 = (code *)0x0;
          }
          else {
            pcVar23 = apcStack_198[0];
            if (apcStack_198[0] != (code *)0x0) {
              *(longlong *)apcStack_198[0] = *(longlong *)apcStack_198[0] + 1;
            }
          }
          *(code **)(auStack_1a8._8_8_ + 0x28) = pcVar23;
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          plVar13 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_1a8._8_8_;
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          *(longlong *)auStack_1a8._0_8_ = *(longlong *)auStack_1a8._0_8_ + -1;
          if (*(longlong *)auStack_1a8._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_1a8._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_198[0] != (code *)0x0) &&
             (*(longlong *)apcStack_198[0] = *(longlong *)apcStack_198[0] + -1,
             *(longlong *)apcStack_198[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_198[0] + 8) + 0x30))();
          }
          pcVar23 = *(code **)(param_1 + 0x138);
          apcStack_198[0] = (code *)0x0;
          auStack_1a8 = (undefined1  [16])0x0;
          pcVar24 = *(code **)PyExc_Exception_exref;
          pcVar22 = *(code **)(pcVar23 + 8);
          if ((*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8) & 0x4000000) == 0) {
            if (((int)*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8) < 0) &&
               (((byte)pcVar24[0xab] & 0x40) != 0)) {
              pcVar4 = *(code **)(pcVar22 + 8);
              pcVar1 = pcVar4 + 0xa8;
              pcVar25 = pcVar23;
              if ((*(uint *)pcVar1 & 0x40000000) == 0) {
                pcVar4 = pcVar22;
                if (((int)*(uint *)pcVar1 < 0) && (((byte)pcVar22[0xab] & 0x40) != 0))
                goto LAB_23e2ec89d;
              }
              else {
                pcVar22 = pcVar4;
                if (*(int *)(*(longlong *)(pcVar4 + 8) + 0xa8) < 0) {
LAB_23e2ec89d:
                  lVar17 = *(longlong *)(pcVar22 + 0x158);
                  if (lVar17 != 0) {
                    if (*(longlong *)(lVar17 + 0x10) < 1) goto LAB_23e2ec4a0;
                    lVar19 = 0;
                    while (pcVar24 != *(code **)(lVar17 + 0x18 + lVar19 * 8)) {
                      lVar19 = lVar19 + 1;
                      if (*(longlong *)(lVar17 + 0x10) == lVar19) goto LAB_23e2ec4a0;
                    }
                    goto LAB_23e2ec5b4;
                  }
                  do {
                    if (pcVar24 == pcVar22) goto LAB_23e2ec5b4;
                    pcVar22 = *(code **)(pcVar22 + 0x100);
                    pcVar4 = PyBaseObject_Type_exref;
                  } while (pcVar22 != (code *)0x0);
                }
              }
              if (pcVar24 != pcVar4) goto LAB_23e2ec4a0;
            }
            else {
LAB_23e2ec548:
              plVar13 = *(longlong **)PyExc_TypeError_exref;
              uVar20 = PyUnicode_FromString
                                 (
                                 "catching classes that do not inherit from BaseException is not allowed"
                                 );
              plVar14 = *(longlong **)(param_1 + 0x60);
              plVar15 = *(longlong **)(param_1 + 0x68);
              plVar16 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar13;
              *plVar13 = *plVar13 + 1;
              *(undefined8 *)(param_1 + 0x68) = uVar20;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0))
              goto LAB_23e2ec5ad;
              (**(code **)(plVar16[1] + 0x30))(plVar16);
              pcVar25 = *(code **)(param_1 + 0x138);
            }
          }
          else {
            lVar17 = *(longlong *)(pcVar24 + 0x10);
            if (lVar17 < 1) {
LAB_23e2ec4a0:
              pcStack_a0 = pcVar23;
              if ((pcVar23 == pcVar26) || (pcVar23 == (code *)0x0)) {
                pcVar24 = (code *)0x0;
                iVar9 = 0x76;
                auVar27 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                pcVar23 = (code *)PyUnicode_FromString();
                pcVar26 = *(code **)(param_1 + 0x138);
                *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
                goto LAB_23e2eda22;
              }
              auVar27 = *(undefined1 (*) [8])(pcVar23 + 8);
              pcVar24 = *(code **)(pcVar23 + 0x28);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
              pcVar26 = pcVar23;
              if (pcVar24 == (code *)0x0) {
                *(longlong **)(param_1 + 0x138) = plVar12;
                iVar9 = 0;
              }
              else {
                *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                if (*(longlong **)(pcVar24 + 0x18) == plVar11) {
                  *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(pcVar24 + 0x24);
                }
                *(longlong **)(param_1 + 0x138) = plVar12;
                iVar9 = 0;
              }
              goto LAB_23e2eda4a;
            }
            lVar19 = 0;
            do {
              if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar24 + lVar19 * 8 + 0x18) + 8) +
                                0xa8)) ||
                 ((*(byte *)(*(longlong *)(pcVar24 + lVar19 * 8 + 0x18) + 0xab) & 0x40) == 0))
              goto LAB_23e2ec548;
              lVar19 = lVar19 + 1;
            } while (lVar17 != lVar19);
            lVar19 = 0;
            while (iVar9 = FUN_23a35ebd0(param_1,pcVar22,
                                         *(undefined8 *)(pcVar24 + lVar19 * 8 + 0x18)), iVar9 == 0)
            {
              lVar19 = lVar19 + 1;
              if (lVar17 == lVar19) {
                pcVar23 = *(code **)(param_1 + 0x138);
                goto LAB_23e2ec4a0;
              }
            }
LAB_23e2ec5ad:
            pcVar25 = *(code **)(param_1 + 0x138);
          }
LAB_23e2ec5b4:
          *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
          plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
          plVar13 = _DAT_23eead248;
          if ((plVar14 != (longlong *)0x0) && (lVar17 = *plVar14, lVar17 != 0)) {
            lVar19 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar19 + 0xe20);
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar2 = plVar14[3];
              *(int *)(lVar19 + 0xebc) = *(int *)(lVar19 + 0xebc) + -1;
              *(longlong *)(lVar19 + 0xe20) = lVar2;
              *plVar14 = 1;
            }
            pcVar23 = _PyRuntime_exref;
            plVar14[4] = 0;
            lVar19 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar14[-1];
            puVar3 = *(undefined8 **)(lVar19 + 8);
            *puVar3 = plVar14 + -2;
            plVar14[-2] = lVar19;
            plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
            *(longlong **)(lVar19 + 8) = plVar14 + -2;
            *plVar13 = *plVar13 + 1;
            plVar14[3] = (longlong)plVar13;
            pcVar23 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e2ec69d;
            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar13 != (longlong *)0x0) goto code_r0x00023e2ed09b;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
LAB_23e2ecf18:
          pcStack_a0 = (code *)PyUnicode_FromFormat
                                         ("cannot access local variable \'%U\' where it is not associated with a value"
                                          ,_DAT_23eead1d8);
          pcVar26 = _Py_NoneStruct_exref;
          auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
          *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
          apcStack_98[0] = (code *)0x0;
          if (auStack_a8 != (undefined1  [8])pcVar26) {
            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
          iVar9 = 0x77;
          pcVar23 = apcStack_98[0];
          auVar27 = auStack_a8;
          pcVar24 = pcStack_a0;
        } while( true );
      }
      plVar13 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd90);
      if (plVar13 == (longlong *)0x0) {
LAB_23e2ec250:
        pcVar23 = *(code **)(param_1 + 0x70);
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        apcStack_98[0] = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
          iVar9 = 0x77;
          pcVar26 = _Py_NoneStruct_exref;
          goto LAB_23e2ec2b0;
        }
        goto LAB_23e2ec533;
      }
      *(undefined4 *)(plVar11 + 5) = 0x77;
      plVar14 = (longlong *)FUN_23e91a870(param_1,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e2ec250;
      plVar13 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd98);
      if (plVar13 == (longlong *)0x0) {
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        pcVar23 = *(code **)(param_1 + 0x70);
        iVar9 = 0x77;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ed579:
        apcStack_98[0] = (code *)0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        goto LAB_23e2ec2b0;
      }
      if (*(longlong *)(pcVar21 + 0x10) == 0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead1d8);
        pcVar26 = _Py_NoneStruct_exref;
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
        apcStack_98[0] = (code *)0x0;
        if (auStack_a8 != (undefined1  [8])pcVar26) {
          FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ed177:
        uVar28 = 0x78;
LAB_23e2ed17d:
        pcVar23 = apcStack_98[0];
        auStack_c8._8_8_ = pcStack_a0;
        auStack_c8._0_8_ = auStack_a8;
        apcStack_98[0] = (code *)0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        apcStack_b8[0] = pcVar23;
        plVar15 = *(longlong **)(param_1 + 0x138);
        if (plVar15 != (longlong *)0x0) {
          *plVar15 = *plVar15 + 1;
        }
        pcVar24 = DAT_23ed6a4f8;
        if (pcVar23 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar23 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar23;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar23 = _PyRuntime_exref;
          *(longlong *)(pcVar24 + 0x10) = 0;
          *(longlong **)(pcVar24 + 0x18) = plVar11;
          *plVar11 = *plVar11 + 1;
          lVar17 = *(longlong *)(pcVar23 + 0x1f8);
          *(undefined4 *)(pcVar24 + 0x24) = uVar28;
          lVar17 = *(longlong *)(lVar17 + 0x10);
          *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
          lVar17 = *(longlong *)(lVar17 + 0x2e8);
          lVar19 = *(longlong *)(pcVar24 + -8);
          puVar3 = *(undefined8 **)(lVar17 + 8);
          *puVar3 = pcVar24 + -0x10;
          *(longlong *)(pcVar24 + -0x10) = lVar17;
          *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
          *(code **)(lVar17 + 8) = pcVar24 + -0x10;
          if ((apcStack_b8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + -1,
             *(longlong *)apcStack_b8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_b8[0] + 8) + 0x30))(apcStack_b8[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar22 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar22;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar22 = _PyRuntime_exref;
          *(longlong **)(pcVar24 + 0x18) = plVar11;
          *plVar11 = *plVar11 + 1;
          lVar17 = *(longlong *)(pcVar22 + 0x1f8);
          *(undefined4 *)(pcVar24 + 0x24) = uVar28;
          *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
          lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
          lVar19 = *(longlong *)(pcVar24 + -8);
          puVar3 = *(undefined8 **)(lVar17 + 8);
          *puVar3 = pcVar24 + -0x10;
          *(longlong *)(pcVar24 + -0x10) = lVar17;
          *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
          *(code **)(lVar17 + 8) = pcVar24 + -0x10;
          *(code **)(pcVar24 + 0x10) = pcVar23;
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
          if ((apcStack_b8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + -1,
             *(longlong *)apcStack_b8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_b8[0] + 8) + 0x30))(apcStack_b8[0]);
          }
        }
        apcStack_b8[0] = pcVar24;
        if (((code *)auStack_c8._0_8_ != pcVar26) && ((code *)auStack_c8._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,auStack_c8,auStack_c8 + 8,apcStack_b8);
        }
        plVar16 = *(longlong **)(auStack_c8._8_8_ + 0x28);
        if (apcStack_b8[0] == pcVar26) {
          pcVar23 = (code *)0x0;
        }
        else {
          pcVar23 = apcStack_b8[0];
          if (apcStack_b8[0] != (code *)0x0) {
            *(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + 1;
          }
        }
        *(code **)(auStack_c8._8_8_ + 0x28) = pcVar23;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        plVar16 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = auStack_c8._8_8_;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        *(longlong *)auStack_c8._0_8_ = *(longlong *)auStack_c8._0_8_ + -1;
        if (*(longlong *)auStack_c8._0_8_ == 0) {
          (**(code **)(*(longlong *)(auStack_c8._0_8_ + 8) + 0x30))();
        }
        if ((apcStack_b8[0] != (code *)0x0) &&
           (*(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + -1,
           *(longlong *)apcStack_b8[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_b8[0] + 8) + 0x30))();
        }
        apcStack_b8[0] = (code *)0x0;
        auStack_c8 = (undefined1  [16])0x0;
        iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8));
        pcVar24 = *(code **)(param_1 + 0x138);
        if (iVar9 == 0) {
          pcStack_a0 = pcVar24;
          if ((pcVar24 == pcVar26) || (pcVar24 == (code *)0x0)) {
            auVar27 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
            pcVar24 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar23 = (code *)0x0;
            pcVar22 = *(code **)(param_1 + 0x138);
            bVar5 = true;
            *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
            goto LAB_23e2ed8b2;
          }
          auVar27 = *(undefined1 (*) [8])(pcVar24 + 8);
          pcVar23 = *(code **)(pcVar24 + 0x28);
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
          if (pcVar23 == (code *)0x0) {
            *(longlong **)(param_1 + 0x138) = plVar15;
            bVar5 = true;
            iVar9 = 0;
            pcVar22 = pcVar24;
          }
          else {
            *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
            if (*(longlong **)(pcVar23 + 0x18) == plVar11) {
              *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(pcVar23 + 0x24);
            }
            bVar5 = true;
LAB_23e2ed48b:
            iVar9 = 0;
            *(longlong **)(param_1 + 0x138) = plVar15;
            pcVar22 = pcVar24;
          }
LAB_23e2ed4b5:
          apcStack_98[0] = (code *)0x0;
          _auStack_a8 = (undefined1  [16])0x0;
          *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
          if (*(longlong *)pcVar22 == 0) {
            (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
          }
        }
        else {
          pcStack_88 = *(code **)(pcVar24 + 8);
          pcStack_78 = *(code **)(pcVar24 + 0x28);
          *(undefined4 *)(plVar11 + 5) = 0x77;
          if (pcStack_78 == (code *)0x0) {
            pcStack_78 = pcVar26;
          }
          pcStack_80 = pcVar24;
          plVar16 = (longlong *)FUN_23e956150(param_1);
          if (plVar16 == (longlong *)0x0) {
            pcVar23 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            bVar5 = false;
            pcVar22 = *(code **)(param_1 + 0x138);
            auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar24 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            iVar9 = FUN_23a35f020(plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))();
            }
            if (iVar9 == -1) {
              auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x68);
              bVar5 = false;
              pcVar23 = *(code **)(param_1 + 0x70);
              pcVar22 = *(code **)(param_1 + 0x138);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              if (iVar9 != 0) {
                plVar16 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar15;
                if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
                goto LAB_23e2ebca5;
              }
              pcVar24 = *(code **)(param_1 + 0x138);
              pcStack_a0 = pcVar24;
              bVar5 = false;
              if ((pcVar24 != pcVar26) && (pcVar24 != (code *)0x0)) {
                auVar27 = *(undefined1 (*) [8])(pcVar24 + 8);
                pcVar23 = *(code **)(pcVar24 + 0x28);
                *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
                if (pcVar23 != (code *)0x0) {
                  *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                  if (*(longlong **)(pcVar23 + 0x18) == plVar11) {
                    *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(pcVar23 + 0x24);
                  }
                  goto LAB_23e2ed48b;
                }
                iVar9 = 0;
                *(longlong **)(param_1 + 0x138) = plVar15;
                pcVar22 = pcVar24;
                goto LAB_23e2ed4b5;
              }
              auVar27 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
              pcVar24 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar22 = *(code **)(param_1 + 0x138);
              pcVar23 = (code *)0x0;
              *(longlong *)auVar27 = *(longlong *)auVar27 + 1;
            }
          }
LAB_23e2ed8b2:
          iVar9 = 0x77;
          *(longlong **)(param_1 + 0x138) = plVar15;
          if (pcVar22 != (code *)0x0) goto LAB_23e2ed4b5;
        }
        apcStack_98[0] = (code *)0x0;
        _auStack_a8 = (undefined1  [16])0x0;
        pcStack_e8 = (code *)auVar27;
        pcStack_e0 = pcVar24;
        pcStack_d8 = pcVar23;
        if (bVar5) {
          *(undefined4 *)(plVar11 + 5) = 0x77;
          plVar15 = (longlong *)FUN_23e957a30(param_1,plVar13,_DAT_23eead100);
          if (plVar15 == (longlong *)0x0) {
            apcStack_98[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            FUN_23a35d6b0();
            iVar9 = 0x77;
            pcVar23 = apcStack_98[0];
            auVar27 = auStack_a8;
            pcVar24 = pcStack_a0;
          }
          else {
            *plVar15 = *plVar15 + -1;
            pcVar23 = pcStack_d8;
            auVar27 = (undefined1  [8])pcStack_e8;
            pcVar24 = pcStack_e0;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))();
              pcVar23 = pcStack_d8;
              auVar27 = (undefined1  [8])pcStack_e8;
              pcVar24 = pcStack_e0;
            }
          }
        }
        goto LAB_23e2ed579;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0f0);
      if (plVar15 == (longlong *)0x0) {
LAB_23e2ed608:
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2ed177;
      }
      plVar16 = (longlong *)FUN_23e8d9440(param_1,plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e2ed608;
      if ((plStack_200 != (longlong *)0x0) &&
         (lVar17 = *plStack_200, *plStack_200 = lVar17 + -1, lVar17 + -1 == 0)) {
        (**(code **)(plStack_200[1] + 0x30))(plStack_200);
      }
      plStack_200 = plVar16;
      if (*(longlong *)(pcVar21 + 0x10) == 0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead1d8);
        pcVar26 = _Py_NoneStruct_exref;
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
        apcStack_98[0] = (code *)0x0;
        if (auStack_a8 != (undefined1  [8])pcVar26) {
          FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2edc47:
        uVar28 = 0x79;
        goto LAB_23e2ed17d;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0b0);
      if (plVar15 == (longlong *)0x0) {
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2edc47;
      }
      if ((plStack_1f8 != (longlong *)0x0) &&
         (lVar17 = *plStack_1f8, *plStack_1f8 = lVar17 + -1, lVar17 + -1 == 0)) {
        (**(code **)(plStack_1f8[1] + 0x30))(plStack_1f8);
      }
      plStack_1f8 = plVar15;
      if (*(longlong *)(pcVar21 + 0x10) == 0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead1d8);
        pcVar26 = _Py_NoneStruct_exref;
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
        apcStack_98[0] = (code *)0x0;
        if (auStack_a8 != (undefined1  [8])pcVar26) {
          FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
        uVar28 = 0x7a;
        goto LAB_23e2ed17d;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0a8);
      if (plVar15 == (longlong *)0x0) {
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        uVar28 = 0x7a;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2ed17d;
      }
      if ((plStack_1f0 != (longlong *)0x0) &&
         (lVar17 = *plStack_1f0, *plStack_1f0 = lVar17 + -1, lVar17 + -1 == 0)) {
        (**(code **)(plStack_1f0[1] + 0x30))(plStack_1f0);
      }
      plStack_1f0 = plVar15;
      if (*(longlong *)(pcVar21 + 0x10) == 0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead1d8);
        pcVar26 = _Py_NoneStruct_exref;
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
        apcStack_98[0] = (code *)0x0;
        if (auStack_a8 != (undefined1  [8])pcVar26) {
          FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
        uVar28 = 0x7b;
        goto LAB_23e2ed17d;
      }
      plVar15 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),DAT_23eead0e0);
      if (plVar15 == (longlong *)0x0) {
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        uVar28 = 0x7b;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2ed17d;
      }
      if ((plStack_1e8 != (longlong *)0x0) &&
         (lVar17 = *plStack_1e8, *plStack_1e8 = lVar17 + -1, lVar17 + -1 == 0)) {
        (**(code **)(plStack_1e8[1] + 0x30))(plStack_1e8);
      }
      *(undefined4 *)(plVar11 + 5) = 0x77;
      plVar16 = (longlong *)FUN_23e957a30(param_1,plVar13,_DAT_23eead100);
      plStack_1e8 = plVar15;
      if (plVar16 == (longlong *)0x0) {
        iVar9 = 0x77;
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e2ed579;
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))();
      }
LAB_23e2ebca5:
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plStack_200 == (longlong *)0x0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead1e0);
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
LAB_23e2ee27c:
        pcVar26 = _Py_NoneStruct_exref;
        apcStack_98[0] = (code *)0x0;
        if (auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
        iVar9 = 0x7d;
        pcVar23 = apcStack_98[0];
        auVar27 = auStack_a8;
        pcVar24 = pcStack_a0;
        goto LAB_23e2ec2b0;
      }
      iVar9 = FUN_23a35f020();
      if (iVar9 == -1) {
LAB_23e2ee007:
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar23 = *(code **)(param_1 + 0x70);
        iVar9 = 0x7d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e2ec2b0;
      }
      if (iVar9 == 0) goto LAB_23e2ec768;
      if (plStack_1f8 == (longlong *)0x0) {
        pcStack_a0 = (code *)PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,_DAT_23eead0b0);
        auStack_a8 = *(undefined1 (*) [8])PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_a8 = *(longlong *)auStack_a8 + 1;
        goto LAB_23e2ee27c;
      }
      iVar9 = FUN_23a35f020();
      if (iVar9 == -1) goto LAB_23e2ee007;
      if (iVar9 != 1) goto LAB_23e2ec768;
      plVar12 = (longlong *)FUN_23ebf7180();
      pcVar23 = DAT_23ed6a4e0;
      if (plVar12 == (longlong *)0x0) {
LAB_23e2ee4b6:
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar23 = *(code **)(param_1 + 0x70);
        iVar9 = 0x7e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar26 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = *(code **)(param_1 + 0x68);
        goto LAB_23e2ec2b0;
      }
      if (DAT_23ed6a4e0 == (code *)0x0) {
        pcVar23 = (code *)FUN_23a33a530(&DAT_23ec0fb60);
      }
      else {
        pcVar24 = *(code **)DAT_23ed6a4e0;
        *(longlong *)DAT_23ed6a4e0 = 1;
        DAT_23ed6a4e0 = pcVar24;
        DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
      }
      pcVar24 = _PyRuntime_exref;
      *(longlong **)(pcVar23 + 0x10) = plVar12;
      *plVar12 = *plVar12 + 1;
      lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar24 + 0x1f8) + 0x10) + 0x2e8);
      lVar19 = *(longlong *)(pcVar23 + -8);
      puVar3 = *(undefined8 **)(lVar17 + 8);
      *puVar3 = pcVar23 + -0x10;
      uVar7 = DAT_23eeb0170;
      uVar6 = _DAT_23eead280;
      *(longlong *)(pcVar23 + -0x10) = lVar17;
      *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
      *(code **)(lVar17 + 8) = pcVar23 + -0x10;
      uVar20 = _DAT_23eead278;
      *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
      pcStack_88 = pcVar23;
      pcStack_80 = pcVar21;
      plVar13 = (longlong *)
                FUN_23e91ecd0(FUN_23e2efe10,uVar7,uVar20,uVar6,_DAT_23eeb00d8,&pcStack_88,2,0x478);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12 = (longlong *)FUN_23e8bd510(param_1,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e2ee4b6;
      if ((plStack_1e0 != (longlong *)0x0) &&
         (lVar17 = *plStack_1e0, *plStack_1e0 = lVar17 + -1, lVar17 + -1 == 0)) {
        (**(code **)(plStack_1e0[1] + 0x30))(plStack_1e0);
      }
      iVar9 = FUN_23a35f020(plVar12);
      plStack_1e0 = plVar12;
      if (iVar9 == 1) {
        if (plStack_1e8 == (longlong *)0x0) {
          FUN_23e8ba2b0(auStack_a8,_DAT_23eead1e8);
          pcVar26 = _Py_NoneStruct_exref;
          if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
             (auStack_a8 != (undefined1  [8])0x0)) {
            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
          iVar9 = 0x80;
          pcVar23 = apcStack_98[0];
          auVar27 = auStack_a8;
          pcVar24 = pcStack_a0;
          goto LAB_23e2ec2b0;
        }
        uVar10 = FUN_23a35f020();
        pcVar26 = _Py_NoneStruct_exref;
        if (uVar10 == 0xffffffff) {
          auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          iVar9 = 0x80;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar24 = *(code **)(param_1 + 0x68);
          goto LAB_23e2ec2b0;
        }
        if ((uVar10 & 1) != 0) {
          iVar9 = FUN_23a35f020(plVar12);
          if (iVar9 == 0) goto LAB_23e2ebead;
          goto LAB_23e2ec768;
        }
        if (*(longlong *)(pcVar21 + 0x10) == 0) {
          FUN_23e8ba2b0(auStack_a8,_DAT_23eead1d8);
          pcVar26 = _Py_NoneStruct_exref;
          if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
             (auStack_a8 != (undefined1  [8])0x0)) {
            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
          iVar9 = 0x81;
          pcVar23 = apcStack_98[0];
          auVar27 = auStack_a8;
          pcVar24 = pcStack_a0;
          goto LAB_23e2ec2b0;
        }
        plVar13 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0d8);
        pcVar26 = _Py_NoneStruct_exref;
        if (plVar13 == (longlong *)0x0) {
          auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          iVar9 = 0x81;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar24 = *(code **)(param_1 + 0x68);
          goto LAB_23e2ec2b0;
        }
        plVar14 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd90);
        if (plVar14 != (longlong *)0x0) {
          *(undefined4 *)(plVar11 + 5) = 0x81;
          plVar15 = (longlong *)FUN_23e91a870(param_1,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            FUN_23a334bc0();
          }
          if (plVar15 != (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd98);
            if (plVar14 == (longlong *)0x0) {
LAB_23e2ef85a:
              auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x68);
              pcVar23 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              iVar9 = 0x81;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              if (*(longlong *)(pcVar21 + 0x10) != 0) {
                cVar8 = FUN_23e8d9ac0(*(longlong *)(pcVar21 + 0x10),DAT_23eead0e0,
                                      _Py_TrueStruct_exref);
                if (cVar8 == '\0') {
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2ee60c;
                }
                *(undefined4 *)(plVar11 + 5) = 0x81;
                plVar16 = (longlong *)FUN_23e957a30(param_1,plVar14);
                if (plVar16 == (longlong *)0x0) goto LAB_23e2ef85a;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0();
                }
LAB_23e2eeb73:
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0(plVar13);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  FUN_23a334bc0(plVar15);
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0(plVar14);
                }
                if (*(longlong *)(pcVar21 + 0x10) == 0) {
                  FUN_23e8ba2b0(auStack_a8,_DAT_23eead1d8);
                  pcVar26 = _Py_NoneStruct_exref;
                  if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                     (auStack_a8 != (undefined1  [8])0x0)) {
                    FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ef741:
                  iVar9 = 0x84;
                  pcVar23 = apcStack_98[0];
                  auVar27 = auStack_a8;
                  pcVar24 = pcStack_a0;
                  goto LAB_23e2ec2b0;
                }
                plVar13 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0e8);
                if (plVar13 == (longlong *)0x0) {
                  auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcVar23 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar26 = _Py_NoneStruct_exref;
                  iVar9 = 0x84;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar24 = *(code **)(param_1 + 0x68);
                  goto LAB_23e2ec2b0;
                }
                iVar9 = FUN_23a35f020();
                lVar17 = *plVar13 + -1;
                if (iVar9 == -1) {
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar13 = lVar17;
                  pcVar26 = _Py_NoneStruct_exref;
                  if (lVar17 == 0) {
                    FUN_23a334bc0();
                    pcVar26 = _Py_NoneStruct_exref;
                  }
                  goto LAB_23e2ef741;
                }
                *plVar13 = lVar17;
                if (lVar17 == 0) {
                  FUN_23a334bc0(plVar13);
                }
                if (iVar9 != 0) {
                  uVar20 = FUN_23a3a0d40(DAT_23ed6cf28);
                  plVar13 = _DAT_23eead1f0;
                  plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                  *plVar13 = *plVar13 + 1;
                  plVar14[3] = (longlong)plVar13;
                  if (plStack_1f0 == (longlong *)0x0) {
                    FUN_23e8ba2b0(auStack_a8,_DAT_23eead1f8);
                    pcVar26 = _Py_NoneStruct_exref;
                    if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                       (auStack_a8 != (undefined1  [8])0x0)) {
                      FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
                    }
                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ef689:
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0();
                    }
                  }
                  else {
                    lVar17 = FUN_23e94f9d0(param_1,plStack_1f0,DAT_23ed6cd28);
                    pcVar26 = _Py_NoneStruct_exref;
                    if (lVar17 == 0) {
                      apcStack_98[0] = *(code **)(param_1 + 0x70);
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e2ef689;
                    }
                    plVar14[4] = lVar17;
                    plVar13 = _DAT_23eead200;
                    *_DAT_23eead200 = *_DAT_23eead200 + 1;
                    plVar14[5] = (longlong)plVar13;
                    plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      FUN_23a334bc0();
                    }
                    pcVar26 = _Py_NoneStruct_exref;
                    if (plVar13 == (longlong *)0x0) {
                      auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcVar23 = *(code **)(param_1 + 0x70);
                      iVar9 = 0x85;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar24 = *(code **)(param_1 + 0x68);
                      goto LAB_23e2ec2b0;
                    }
                    *(undefined4 *)(plVar11 + 5) = 0x85;
                    plVar14 = (longlong *)FUN_23e914090(param_1,uVar20,plVar13);
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0();
                    }
                    pcVar26 = _Py_NoneStruct_exref;
                    if (plVar14 != (longlong *)0x0) {
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                      uVar20 = FUN_23a3a0d40(DAT_23ed6cf28);
                      plVar13 = _DAT_23eead208;
                      plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                      *plVar13 = *plVar13 + 1;
                      plVar14[3] = (longlong)plVar13;
                      lVar17 = FUN_23e94f9d0(param_1,plStack_1f0,DAT_23ed6cd28);
                      if (lVar17 == 0) {
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                      }
                      else {
                        plVar14[4] = lVar17;
                        plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar13 != (longlong *)0x0) {
                          *(undefined4 *)(plVar11 + 5) = 0x86;
                          plVar14 = (longlong *)FUN_23e914090(param_1,uVar20,plVar13);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar14 != (longlong *)0x0) {
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                            }
                            uVar20 = FUN_23a3a0d40(DAT_23ed6cf28);
                            *(undefined4 *)(plVar11 + 5) = 0x87;
                            plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar20,_DAT_23eead210);
                            if (plVar13 == (longlong *)0x0) {
                              auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcVar23 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              pcVar26 = _Py_NoneStruct_exref;
                              iVar9 = 0x87;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar24 = *(code **)(param_1 + 0x68);
                              goto LAB_23e2ec2b0;
                            }
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0();
                            }
                            uVar20 = FUN_23a3a0d40(DAT_23ed6cf28);
                            *(undefined4 *)(plVar11 + 5) = 0x88;
                            plVar13 = (longlong *)FUN_23e94bb80(param_1,uVar20,_DAT_23eead218);
                            if (plVar13 == (longlong *)0x0) {
                              auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcVar23 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              pcVar26 = _Py_NoneStruct_exref;
                              iVar9 = 0x88;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar24 = *(code **)(param_1 + 0x68);
                              goto LAB_23e2ec2b0;
                            }
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              FUN_23a334bc0();
                            }
                            plStack_1e0 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
                            plVar13 = _DAT_23eead220;
                            plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                            *plVar13 = *plVar13 + 1;
                            plVar14[3] = (longlong)plVar13;
                            goto LAB_23e2eec33;
                          }
                        }
                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      iVar9 = 0x86;
                      pcVar26 = _Py_NoneStruct_exref;
                      pcVar23 = apcStack_98[0];
                      auVar27 = auStack_a8;
                      pcVar24 = pcStack_a0;
                      goto LAB_23e2ec2b0;
                    }
                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  iVar9 = 0x85;
                  pcVar23 = apcStack_98[0];
                  auVar27 = auStack_a8;
                  pcVar24 = pcStack_a0;
                  goto LAB_23e2ec2b0;
                }
                plStack_1e0 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
                plVar13 = _DAT_23eead220;
                plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                *plVar13 = *plVar13 + 1;
                plVar14[3] = (longlong)plVar13;
                if (plStack_1f0 == (longlong *)0x0) {
                  FUN_23e8ba2b0(auStack_a8,_DAT_23eead1f8);
                  pcVar26 = _Py_NoneStruct_exref;
                  if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                     (auStack_a8 != (undefined1  [8])0x0)) {
                    FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ef232:
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0();
                  }
LAB_23e2eed2f:
                  iVar9 = 0x89;
                  plStack_1e0 = plVar12;
                  pcVar23 = apcStack_98[0];
                  auVar27 = auStack_a8;
                  pcVar24 = pcStack_a0;
                  goto LAB_23e2ec2b0;
                }
LAB_23e2eec33:
                lVar17 = FUN_23e94f9d0(param_1,plStack_1f0,DAT_23ed6cd28);
                if (lVar17 == 0) {
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar26 = _Py_NoneStruct_exref;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2ef232;
                }
                plVar14[4] = lVar17;
                plVar13 = _DAT_23eead228;
                *_DAT_23eead228 = *_DAT_23eead228 + 1;
                plVar14[5] = (longlong)plVar13;
                plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar13 == (longlong *)0x0) {
                  auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcVar23 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar26 = _Py_NoneStruct_exref;
                  iVar9 = 0x89;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plStack_1e0 = plVar12;
                  pcVar24 = *(code **)(param_1 + 0x68);
                  goto LAB_23e2ec2b0;
                }
                *(undefined4 *)(plVar11 + 5) = 0x89;
                plVar14 = (longlong *)FUN_23e914090(param_1,plStack_1e0,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar14 == (longlong *)0x0) {
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar26 = _Py_NoneStruct_exref;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2eed2f;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0(plVar14);
                }
                *(undefined4 *)(plVar11 + 5) = 0x8c;
                plVar13 = (longlong *)FUN_23e91a870(param_1,plStack_1f8);
                if (plVar13 == (longlong *)0x0) {
                  uStack_148 = *(undefined8 *)(param_1 + 0x60);
                  uStack_140 = *(undefined8 *)(param_1 + 0x68);
                  plVar13 = *(longlong **)(param_1 + 0x70);
                  plVar14 = *(longlong **)(param_1 + 0x138);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  apcStack_98[0] = (code *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  auStack_a8 = (undefined1  [8])0x0;
                  pcStack_a0 = (code *)0x0;
                  if (plVar14 != (longlong *)0x0) {
                    *plVar14 = *plVar14 + 1;
                  }
                  plStack_138 = plVar13;
                  if (plVar13 == (longlong *)0x0) {
                    lVar17 = FUN_23e8d6280(plVar11,0x8c);
                  }
                  else {
                    lVar17 = FUN_23e8d6280(plVar11,0x8c);
                    *(longlong **)(lVar17 + 0x10) = plVar13;
                    *plVar13 = *plVar13 + 1;
                  }
                  if ((plStack_138 != (longlong *)0x0) &&
                     (*plStack_138 = *plStack_138 + -1, *plStack_138 == 0)) {
                    FUN_23a334bc0();
                  }
                  plStack_138 = (longlong *)lVar17;
                  FUN_23a35ef40(param_1,&uStack_148);
                  iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                        *(undefined8 *)PyExc_Exception_exref);
                  uVar20 = DAT_23ed6cf28;
                  if (iVar9 == 0) {
                    cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                    iVar9 = 0;
                    if (cVar8 == '\0') {
                      iVar9 = 0x8b;
                    }
                    pcVar26 = _Py_NoneStruct_exref;
                    pcVar23 = apcStack_98[0];
                    auVar27 = auStack_a8;
                    pcVar24 = pcStack_a0;
                    if ((apcStack_98[0] != (code *)0x0) &&
                       (*(longlong **)(apcStack_98[0] + 0x18) == plVar11)) {
                      *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
                      pcVar26 = _Py_NoneStruct_exref;
                    }
                  }
                  else {
                    plVar13 = *(longlong **)(param_1 + 0x138);
                    *plVar13 = *plVar13 + 1;
                    uVar20 = FUN_23a3a0d40(uVar20);
                    plVar15 = _DAT_23eead230;
                    plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                    *plVar15 = *plVar15 + 1;
                    plVar16[3] = (longlong)plVar15;
                    lVar17 = FUN_23e94f9d0(param_1,plVar13,DAT_23ed6cd28);
                    if (lVar17 == 0) {
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      apcStack_98[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
LAB_23e2ef13d:
                      iVar9 = 0x8e;
                      pcVar26 = _Py_NoneStruct_exref;
                    }
                    else {
                      plVar16[4] = lVar17;
                      plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
                      if (plVar15 == (longlong *)0x0) {
LAB_23e2ef114:
                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e2ef13d;
                      }
                      *(undefined4 *)(plVar11 + 5) = 0x8e;
                      plVar16 = (longlong *)FUN_23e914090(param_1,uVar20,plVar15);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      if (plVar16 == (longlong *)0x0) goto LAB_23e2ef114;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
                      pcVar26 = _Py_NoneStruct_exref;
                      uVar6 = _DAT_23eead238;
                      uVar20 = DAT_23ed6ccf0;
                      *(undefined4 *)(plVar11 + 5) = 0x8f;
                      plVar15 = (longlong *)
                                FUN_23e95c160(param_1,uVar6,DAT_23eead080,pcVar26,pcVar26,uVar20);
                      if (plVar15 == (longlong *)0x0) {
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                        iVar9 = 0x8f;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        if ((plStack_1d8 != (longlong *)0x0) &&
                           (lVar17 = *plStack_1d8, *plStack_1d8 = lVar17 + -1, lVar17 + -1 == 0)) {
                          FUN_23a334bc0(plStack_1d8);
                        }
                        *(undefined4 *)(plVar11 + 5) = 0x90;
                        plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar15,_DAT_23eead240);
                        plStack_1d8 = plVar15;
                        if (plVar16 != (longlong *)0x0) {
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            FUN_23a334bc0(plVar16);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          FUN_23ebf6ae0(param_1,plVar14);
                          plStack_1e0 = plVar12;
                          goto LAB_23e2ec768;
                        }
                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        iVar9 = 0x90;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                    }
                    pcVar23 = apcStack_98[0];
                    pcVar24 = pcStack_a0;
                    auVar27 = auStack_a8;
                    _auStack_a8 = (undefined1  [16])0x0;
                    apcStack_98[0] = (code *)0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      FUN_23a334bc0(plVar13);
                    }
                  }
                  pcStack_a0 = pcVar24;
                  auStack_a8 = auVar27;
                  pcVar24 = pcStack_a0;
                  auVar27 = auStack_a8;
                  apcStack_98[0] = (code *)0x0;
                  _auStack_a8 = (undefined1  [16])0x0;
                  FUN_23ebf6ae0(param_1,plVar14);
                  plStack_1e0 = plVar12;
                  goto LAB_23e2ec2b0;
                }
                *plVar13 = *plVar13 + -1;
                lVar17 = *plVar13;
                goto joined_r0x00023e2eecee;
              }
              FUN_23e8ba2b0(auStack_a8,_DAT_23eead1d8);
              if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                 (auStack_a8 != (undefined1  [8])0x0)) {
                FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ee60c:
              pcVar23 = apcStack_98[0];
              apcStack_98[0] = (code *)0x0;
              pcStack_f8 = pcVar23;
              plVar16 = *(longlong **)(param_1 + 0x138);
              pcStack_108 = (code *)auStack_a8;
              pcStack_100 = pcStack_a0;
              auStack_a8 = (undefined1  [8])0x0;
              pcStack_a0 = (code *)0x0;
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + 1;
              }
              if (pcVar23 == (code *)0x0) {
                lVar17 = FUN_23e8d6280(plVar11,0x82);
              }
              else {
                lVar17 = FUN_23e8d6280(plVar11,0x82);
                *(code **)(lVar17 + 0x10) = pcVar23;
                *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              }
              if ((pcStack_f8 != (code *)0x0) &&
                 (*(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + -1,
                 *(longlong *)pcStack_f8 == 0)) {
                FUN_23a334bc0();
              }
              pcStack_f8 = (code *)lVar17;
              FUN_23a35ef40(param_1,&pcStack_108);
              iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                    *(undefined8 *)PyExc_BaseException_exref);
              if (iVar9 == 0) {
                cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                pcVar24 = apcStack_98[0];
                pcVar23 = pcStack_a0;
                auVar27 = auStack_a8;
                iVar9 = 0;
                if (cVar8 == '\0') {
                  iVar9 = 0x81;
                }
                if ((apcStack_98[0] != (code *)0x0) &&
                   (*(longlong **)(apcStack_98[0] + 0x18) == plVar11)) {
                  *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
                }
                apcStack_98[0] = (code *)0x0;
                _auStack_a8 = (undefined1  [16])0x0;
                FUN_23ebf6ae0(param_1,plVar16);
                *(undefined4 *)(plVar11 + 5) = 0x81;
                pcStack_118 = pcVar24;
                apcStack_98[0] = (code *)0x0;
                pcStack_128 = (code *)auVar27;
                pcStack_120 = pcVar23;
                _auStack_a8 = (undefined1  [16])0x0;
                plVar12 = (longlong *)FUN_23e957a30(param_1,plVar14,_DAT_23eead100);
                if (plVar12 == (longlong *)0x0) {
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  FUN_23a35d6b0();
                  iVar9 = 0x81;
                  pcVar23 = apcStack_98[0];
                  auVar27 = auStack_a8;
                  pcVar24 = pcStack_a0;
                }
                else {
                  *plVar12 = *plVar12 + -1;
                  pcVar23 = pcStack_118;
                  auVar27 = (undefined1  [8])pcStack_128;
                  pcVar24 = pcStack_120;
                  if (*plVar12 == 0) {
                    FUN_23a334bc0();
                    pcVar23 = pcStack_118;
                    auVar27 = (undefined1  [8])pcStack_128;
                    pcVar24 = pcStack_120;
                  }
                }
                goto LAB_23e2ee840;
              }
              pcStack_80 = *(code **)(param_1 + 0x138);
              pcStack_88 = *(code **)(pcStack_80 + 8);
              pcStack_78 = *(code **)(pcStack_80 + 0x28);
              if (*(code **)(pcStack_80 + 0x28) == (code *)0x0) {
                pcStack_78 = _Py_NoneStruct_exref;
              }
              *(undefined4 *)(plVar11 + 5) = 0x81;
              plVar18 = (longlong *)FUN_23e956150(param_1,plVar14,&pcStack_88);
              if (plVar18 == (longlong *)0x0) {
LAB_23e2ef979:
                auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_a0 = *(code **)(param_1 + 0x68);
                pcVar23 = *(code **)(param_1 + 0x70);
                iVar9 = 0x81;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                iVar9 = FUN_23a35f020(plVar18);
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  FUN_23a334bc0();
                }
                if (iVar9 == -1) goto LAB_23e2ef979;
                if (iVar9 != 0) {
                  FUN_23ebf6ae0(param_1,plVar16);
                  goto LAB_23e2eeb73;
                }
                cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                iVar9 = 0;
                if (cVar8 == '\0') {
                  iVar9 = 0x81;
                }
                pcVar23 = apcStack_98[0];
                if ((apcStack_98[0] != (code *)0x0) &&
                   (*(longlong **)(apcStack_98[0] + 0x18) == plVar11)) {
                  *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
                }
              }
              pcVar24 = pcStack_a0;
              auVar27 = auStack_a8;
              apcStack_98[0] = (code *)0x0;
              _auStack_a8 = (undefined1  [16])0x0;
              FUN_23ebf6ae0(param_1,plVar16);
              pcStack_128 = (code *)auVar27;
              pcStack_120 = pcVar24;
              pcStack_118 = pcVar23;
            }
LAB_23e2ee840:
            apcStack_98[0] = (code *)0x0;
            auStack_a8 = (undefined1  [8])0x0;
            pcStack_a0 = (code *)0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))();
            }
            pcVar26 = _Py_NoneStruct_exref;
            if ((plVar14 != (longlong *)0x0) &&
               (*plVar14 = *plVar14 + -1, pcVar26 = _Py_NoneStruct_exref, *plVar14 == 0)) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            goto LAB_23e2ec2b0;
          }
        }
        pcVar23 = *(code **)(param_1 + 0x70);
        auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar24 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        apcStack_98[0] = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        iVar9 = 0x81;
        pcVar26 = _Py_NoneStruct_exref;
        goto LAB_23e2ec2b0;
      }
      iVar9 = FUN_23a35f020(plVar12);
      if (iVar9 == 0) {
        if (plStack_1e8 == (longlong *)0x0) {
          FUN_23e8ba2b0(auStack_a8,_DAT_23eead1e8);
          pcVar26 = _Py_NoneStruct_exref;
          if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
             (auStack_a8 != (undefined1  [8])0x0)) {
            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
          iVar9 = 0x92;
          pcVar23 = apcStack_98[0];
          auVar27 = auStack_a8;
          pcVar24 = pcStack_a0;
          goto LAB_23e2ec2b0;
        }
LAB_23e2ebead:
        iVar9 = FUN_23a35f020();
        if (iVar9 == -1) {
          auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcVar23 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar26 = _Py_NoneStruct_exref;
          iVar9 = 0x92;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar24 = *(code **)(param_1 + 0x68);
          goto LAB_23e2ec2b0;
        }
        if (iVar9 != 1) goto LAB_23e2ec768;
        if (*(longlong *)(pcVar21 + 0x10) == 0) {
          FUN_23e8ba2b0(auStack_a8,_DAT_23eead1d8);
          pcVar26 = _Py_NoneStruct_exref;
          if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
             (auStack_a8 != (undefined1  [8])0x0)) {
            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
        }
        else {
          plVar14 = (longlong *)FUN_23e8bc2f0(*(longlong *)(pcVar21 + 0x10),_DAT_23eead0d8);
          if (plVar14 != (longlong *)0x0) {
            plVar13 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd90);
            if (plVar13 == (longlong *)0x0) {
LAB_23e2efa2e:
              auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcVar24 = *(code **)(param_1 + 0x68);
              pcVar23 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar14 = *plVar14 + -1;
              if (*plVar14 != 0) {
                iVar9 = 0x93;
                pcVar26 = _Py_NoneStruct_exref;
                goto LAB_23e2ec2b0;
              }
              plVar15 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              iVar9 = 0x93;
LAB_23e2efa83:
              pcStack_a0 = (code *)0x0;
              auStack_a8 = (undefined1  [8])0x0;
              apcStack_98[0] = (code *)0x0;
              FUN_23a334bc0();
              if (plVar15 != (longlong *)0x0) goto LAB_23e2ec1f2;
            }
            else {
              *(undefined4 *)(plVar11 + 5) = 0x93;
              plVar15 = (longlong *)FUN_23e91a870(param_1,plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                FUN_23a334bc0();
              }
              if (plVar15 == (longlong *)0x0) goto LAB_23e2efa2e;
              plVar13 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd98);
              if (plVar13 == (longlong *)0x0) {
LAB_23e2efaae:
                auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_a0 = *(code **)(param_1 + 0x68);
                apcStack_98[0] = *(code **)(param_1 + 0x70);
                iVar9 = 0x93;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                if (*(longlong *)(pcVar21 + 0x10) != 0) {
                  cVar8 = FUN_23e8d9ac0(*(longlong *)(pcVar21 + 0x10),DAT_23eead0e0);
                  if (cVar8 == '\0') {
                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e2ebfa5;
                  }
                  *(undefined4 *)(plVar11 + 5) = 0x93;
                  plVar16 = (longlong *)FUN_23e957a30(param_1,plVar13,_DAT_23eead100);
                  if (plVar16 == (longlong *)0x0) goto LAB_23e2efaae;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0();
                  }
LAB_23e2efba7:
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    FUN_23a334bc0(plVar15);
                  }
                  *plVar13 = *plVar13 + -1;
                  lVar17 = *plVar13;
joined_r0x00023e2eecee:
                  plStack_1e0 = plVar12;
                  if (lVar17 == 0) {
                    FUN_23a334bc0(plVar13);
                  }
                  goto LAB_23e2ec768;
                }
                FUN_23e8ba2b0(auStack_a8,_DAT_23eead1d8);
                if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                   (auStack_a8 != (undefined1  [8])0x0)) {
                  FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
                }
                FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
LAB_23e2ebfa5:
                pcVar23 = apcStack_98[0];
                plVar16 = *(longlong **)(param_1 + 0x138);
                apcStack_98[0] = (code *)0x0;
                pcStack_158 = pcVar23;
                pcStack_168 = (code *)auStack_a8;
                pcStack_160 = pcStack_a0;
                auStack_a8 = (undefined1  [8])0x0;
                pcStack_a0 = (code *)0x0;
                if (plVar16 != (longlong *)0x0) {
                  *plVar16 = *plVar16 + 1;
                }
                if (pcVar23 == (code *)0x0) {
                  lVar17 = FUN_23e8d6280(plVar11,0x94);
                }
                else {
                  lVar17 = FUN_23e8d6280(plVar11,0x94);
                  *(code **)(lVar17 + 0x10) = pcVar23;
                  *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                }
                if ((pcStack_158 != (code *)0x0) &&
                   (*(longlong *)pcStack_158 = *(longlong *)pcStack_158 + -1,
                   *(longlong *)pcStack_158 == 0)) {
                  FUN_23a334bc0();
                }
                pcStack_158 = (code *)lVar17;
                FUN_23a35ef40(param_1,&pcStack_168);
                iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                      *(undefined8 *)PyExc_BaseException_exref);
                if (iVar9 == 0) {
                  cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138));
                  pcVar24 = apcStack_98[0];
                  pcVar23 = pcStack_a0;
                  auVar27 = auStack_a8;
                  iVar9 = 0;
                  if (cVar8 == '\0') {
                    iVar9 = 0x93;
                  }
                  if ((apcStack_98[0] != (code *)0x0) &&
                     (*(longlong **)(apcStack_98[0] + 0x18) == plVar11)) {
                    *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
                  }
                  apcStack_98[0] = (code *)0x0;
                  _auStack_a8 = (undefined1  [16])0x0;
                  FUN_23ebf6ae0(param_1,plVar16);
                  *(undefined4 *)(plVar11 + 5) = 0x93;
                  apcStack_98[0] = (code *)0x0;
                  pcStack_178 = pcVar24;
                  pcStack_188 = (code *)auVar27;
                  pcStack_180 = pcVar23;
                  _auStack_a8 = (undefined1  [16])0x0;
                  plVar12 = (longlong *)FUN_23e957a30(param_1,plVar13,_DAT_23eead100);
                  if (plVar12 == (longlong *)0x0) {
                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    FUN_23a35d6b0();
                    iVar9 = 0x93;
                    goto LAB_23e2ec1c1;
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    FUN_23a334bc0();
                  }
                }
                else {
                  pcStack_80 = *(code **)(param_1 + 0x138);
                  pcStack_88 = *(code **)(pcStack_80 + 8);
                  pcStack_78 = *(code **)(pcStack_80 + 0x28);
                  if (*(code **)(pcStack_80 + 0x28) == (code *)0x0) {
                    pcStack_78 = _Py_NoneStruct_exref;
                  }
                  *(undefined4 *)(plVar11 + 5) = 0x93;
                  plVar18 = (longlong *)FUN_23e956150(param_1);
                  if (plVar18 == (longlong *)0x0) {
LAB_23e2efbe2:
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    pcVar23 = *(code **)(param_1 + 0x70);
                    iVar9 = 0x93;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    iVar9 = FUN_23a35f020(plVar18);
                    *plVar18 = *plVar18 + -1;
                    if (*plVar18 == 0) {
                      FUN_23a334bc0();
                    }
                    if (iVar9 == -1) goto LAB_23e2efbe2;
                    if (iVar9 != 0) {
                      FUN_23ebf6ae0(param_1,plVar16);
                      goto LAB_23e2efba7;
                    }
                    cVar8 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                    iVar9 = 0;
                    if (cVar8 == '\0') {
                      iVar9 = 0x93;
                    }
                    pcVar23 = apcStack_98[0];
                    if ((apcStack_98[0] != (code *)0x0) &&
                       (*(longlong **)(apcStack_98[0] + 0x18) == plVar11)) {
                      *(undefined4 *)(plVar11 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
                    }
                  }
                  pcVar24 = pcStack_a0;
                  auVar27 = auStack_a8;
                  apcStack_98[0] = (code *)0x0;
                  _auStack_a8 = (undefined1  [16])0x0;
                  FUN_23ebf6ae0(param_1,plVar16);
                  pcStack_188 = (code *)auVar27;
                  pcStack_180 = pcVar24;
                  pcStack_178 = pcVar23;
                }
                apcStack_98[0] = pcStack_178;
                auStack_a8 = (undefined1  [8])pcStack_188;
                pcStack_a0 = pcStack_180;
              }
LAB_23e2ec1c1:
              pcVar23 = apcStack_98[0];
              pcVar24 = pcStack_a0;
              auVar27 = auStack_a8;
              auStack_a8 = (undefined1  [8])0x0;
              pcStack_a0 = (code *)0x0;
              apcStack_98[0] = (code *)0x0;
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) goto LAB_23e2efa83;
LAB_23e2ec1f2:
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                FUN_23a334bc0();
              }
            }
            pcVar26 = _Py_NoneStruct_exref;
            if ((plVar13 != (longlong *)0x0) &&
               (*plVar13 = *plVar13 + -1, pcVar26 = _Py_NoneStruct_exref, *plVar13 == 0)) {
              FUN_23a334bc0();
              pcVar26 = _Py_NoneStruct_exref;
            }
            goto LAB_23e2ec2b0;
          }
          apcStack_98[0] = *(code **)(param_1 + 0x70);
          auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_a0 = *(code **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar26 = _Py_NoneStruct_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        iVar9 = 0x93;
        pcVar23 = apcStack_98[0];
        auVar27 = auStack_a8;
        pcVar24 = pcStack_a0;
        goto LAB_23e2ec2b0;
      }
      goto LAB_23e2ec768;
    }
LAB_23e2ed840:
    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_a0 = *(code **)(param_1 + 0x68);
    apcStack_98[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  if (apcStack_98[0] == (code *)0x0) {
    iVar9 = 0x75;
LAB_23e2ecde0:
    pcVar24 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar23 = apcStack_98[0];
    }
    else {
      pcVar23 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar23;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar23 = (code *)0x0;
    }
    pcVar26 = _PyRuntime_exref;
    *(longlong *)(pcVar24 + 0x10) = 0;
    *(longlong **)(pcVar24 + 0x18) = plVar11;
    *plVar11 = *plVar11 + 1;
    lVar17 = *(longlong *)(pcVar26 + 0x1f8);
    *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
    lVar17 = *(longlong *)(lVar17 + 0x10);
    *(int *)(pcVar24 + 0x24) = iVar9;
    lVar17 = *(longlong *)(lVar17 + 0x2e8);
    lVar19 = *(longlong *)(pcVar24 + -8);
    puVar3 = *(undefined8 **)(lVar17 + 8);
    *puVar3 = pcVar24 + -0x10;
    *(longlong *)(pcVar24 + -0x10) = lVar17;
    *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
    *(code **)(lVar17 + 8) = pcVar24 + -0x10;
  }
  else {
    iVar9 = 0x75;
    plVar12 = *(longlong **)(apcStack_98[0] + 0x18);
joined_r0x00023e2ee0af:
    pcVar24 = apcStack_98[0];
    if (plVar12 == plVar11) goto LAB_23e2eca0e;
LAB_23e2ec968:
    pcVar23 = apcStack_98[0];
    pcVar24 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar26 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar26;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar26 = _PyRuntime_exref;
    *(longlong **)(pcVar24 + 0x18) = plVar11;
    *plVar11 = *plVar11 + 1;
    lVar17 = *(longlong *)(pcVar26 + 0x1f8);
    *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
    *(int *)(pcVar24 + 0x24) = iVar9;
    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
    lVar19 = *(longlong *)(pcVar24 + -8);
    puVar3 = *(undefined8 **)(lVar17 + 8);
    *puVar3 = pcVar24 + -0x10;
    *(longlong *)(pcVar24 + -0x10) = lVar17;
    *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar19 & 3) | (ulonglong)puVar3;
    *(code **)(lVar17 + 8) = pcVar24 + -0x10;
    *(code **)(pcVar24 + 0x10) = pcVar23;
    *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
    pcVar23 = apcStack_98[0];
  }
  if ((pcVar23 != (code *)0x0) &&
     (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
    (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
  }
LAB_23e2eca0e:
  apcStack_98[0] = pcVar24;
  FUN_23e8bba40(plVar11,"cooooooo",pcVar21,plStack_200,plStack_1f8,plStack_1f0,plStack_1e8,
                plStack_1e0,0,plStack_1d8);
  if (_DAT_23eeb00f0 == plVar11) {
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    _DAT_23eeb00f0 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar17 + 0x28);
  plVar12 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  pcVar24 = apcStack_98[0];
  pcVar23 = pcStack_a0;
  auVar27 = auStack_a8;
  plVar11[0xf] = 0;
  _auStack_a8 = (undefined1  [16])0x0;
  apcStack_98[0] = (code *)0x0;
  *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
  if (*(longlong *)pcVar21 == 0) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  if ((plStack_200 != (longlong *)0x0) &&
     (lVar17 = *plStack_200, *plStack_200 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_200[1] + 0x30))(plStack_200);
  }
  if ((plStack_1f8 != (longlong *)0x0) &&
     (lVar17 = *plStack_1f8, *plStack_1f8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_1f8[1] + 0x30))(plStack_1f8);
  }
  if ((plStack_1f0 != (longlong *)0x0) &&
     (lVar17 = *plStack_1f0, *plStack_1f0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_1f0[1] + 0x30))(plStack_1f0);
  }
  if ((plStack_1e8 != (longlong *)0x0) &&
     (lVar17 = *plStack_1e8, *plStack_1e8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_1e8[1] + 0x30))(plStack_1e8);
  }
  if ((plStack_1e0 != (longlong *)0x0) &&
     (lVar17 = *plStack_1e0, *plStack_1e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_1e0[1] + 0x30))(plStack_1e0);
  }
  if ((plStack_1d8 != (longlong *)0x0) &&
     (lVar17 = *plStack_1d8, *plStack_1d8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_1d8[1] + 0x30))(plStack_1d8);
  }
  _auStack_a8 = CONCAT88(pcVar23,auVar27);
  apcStack_98[0] = pcVar24;
  FUN_23a33aa70(param_1,auVar27,pcVar23,pcVar24);
  return (code *)0x0;
code_r0x00023e2ed09b:
  *plVar13 = *plVar13 + 1;
  DAT_23ed6a4c0 = plVar13;
LAB_23e2ec69d:
  pcStack_80 = pcVar23;
  pcStack_88 = pcVar25;
  lVar19 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
  if (lVar19 == 0) {
    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_a0 = *(code **)(param_1 + 0x68);
    apcStack_98[0] = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar14 = *plVar14 + -1;
    pcVar23 = pcStack_a0;
    auVar27 = auStack_a8;
    pcVar24 = apcStack_98[0];
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
      pcVar23 = pcStack_a0;
      auVar27 = auStack_a8;
      pcVar24 = apcStack_98[0];
    }
    goto LAB_23e2ed9dd;
  }
  plVar14[4] = lVar19;
  plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))();
  }
  if (plVar13 != (longlong *)0x0) {
    *(undefined4 *)(plVar11 + 5) = 0x97;
    plVar14 = (longlong *)FUN_23e914090(param_1,lVar17,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
      if (*(longlong *)pcVar25 == 0) {
        (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
      }
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar12;
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))();
      }
LAB_23e2ec768:
      lVar17 = *(longlong *)(DAT_23eead080 + 0x20);
      if (*(char *)(lVar17 + 10) == '\0') {
        plVar12 = (longlong *)FUN_23a37a020(DAT_23eead080,_DAT_23eead250);
        if (plVar12 == (longlong *)0x0) goto LAB_23e2ec909;
        lVar19 = *plVar12;
LAB_23e2ed670:
        if (lVar19 == 0) goto LAB_23e2ec909;
      }
      else {
        iVar9 = *(int *)(lVar17 + 0xc);
        if (*(int *)(lVar17 + 0xc) == 0) {
          *(int *)(lVar17 + 0xc) = DAT_23ec14e3c;
          iVar9 = DAT_23ec14e3c;
          DAT_23ec14e3c = DAT_23ec14e3c + 1;
        }
        if (_DAT_23ec14e34 != iVar9) {
          _DAT_23ec14e34 = iVar9;
          _DAT_23eeb00e0 =
               FUN_23e8cbd60(lVar17,_DAT_23eead250,*(undefined8 *)(_DAT_23eead250 + 0x18));
        }
        if (-1 < _DAT_23eeb00e0) {
          lVar2 = lVar17 + 0x20 + (1L << (*(byte *)(lVar17 + 9) & 0x3f));
          lVar19 = *(longlong *)(lVar2 + 8 + _DAT_23eeb00e0 * 0x10);
          if (lVar19 != 0) goto LAB_23e2ec7d5;
          _DAT_23eeb00e0 =
               FUN_23e8cbd60(lVar17,_DAT_23eead250,*(undefined8 *)(_DAT_23eead250 + 0x18));
          if (-1 < _DAT_23eeb00e0) {
            lVar19 = *(longlong *)(lVar2 + 8 + _DAT_23eeb00e0 * 0x10);
            goto LAB_23e2ed670;
          }
        }
LAB_23e2ec909:
        plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eead250);
        if ((plVar12 == (longlong *)0x0) || (lVar19 = *plVar12, lVar19 == 0)) {
          iVar29 = 0x99;
          FUN_23e915740(param_1,auStack_a8,_DAT_23eead250);
          if (apcStack_98[0] == (code *)0x0) goto LAB_23e2ee0ba;
          goto LAB_23e2ec95e;
        }
      }
LAB_23e2ec7d5:
      lVar17 = _DAT_23eead260;
      *(undefined4 *)(plVar11 + 5) = 0x99;
      plVar12 = (longlong *)
                FUN_23e915840(param_1,lVar19,_DAT_23eead258,*(undefined8 *)(lVar17 + 0x18));
      if (plVar12 == (longlong *)0x0) {
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_98[0] != (code *)0x0) {
          plVar12 = *(longlong **)(apcStack_98[0] + 0x18);
          iVar9 = 0x99;
          goto joined_r0x00023e2ee0af;
        }
LAB_23e2ee0ba:
        iVar9 = 0x99;
        goto LAB_23e2ecde0;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      lVar17 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) == 0) && (*(int *)(lVar17 + 0x78) == 0))
          || (iVar9 = Py_MakePendingCalls(), -1 < iVar9)) ||
         (pcVar23 = *(code **)(param_1 + 0x60), pcVar23 == (code *)0x0)) {
        if (*(int *)(lVar17 + 0x68) == 0) {
          plVar12 = *(longlong **)(param_1 + 0x90);
        }
        else {
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
          plVar12 = *(longlong **)(param_1 + 0x90);
        }
        if (plVar12 == (longlong *)0x0) {
          lVar17 = *(longlong *)(pcVar21 + 0x10);
          goto LAB_23e2eba21;
        }
        plVar13 = *(longlong **)(param_1 + 0x60);
        plVar14 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar12;
        *plVar12 = *plVar12 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
        }
        pcVar23 = *(code **)(param_1 + 0x60);
      }
      apcStack_98[0] = *(code **)(param_1 + 0x70);
      iVar29 = 0x75;
      iVar9 = 0x75;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_a0 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      auStack_a8 = (undefined1  [8])pcVar23;
      if (apcStack_98[0] == (code *)0x0) goto LAB_23e2ecde0;
LAB_23e2ec95e:
      plVar12 = *(longlong **)(apcStack_98[0] + 0x18);
      iVar9 = iVar29;
      goto joined_r0x00023e2ee0af;
    }
  }
  pcVar24 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  auVar27 = *(undefined1 (*) [8])(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  pcVar23 = *(code **)(param_1 + 0x68);
LAB_23e2ed9dd:
  apcStack_98[0] = (code *)0x0;
  _auStack_a8 = (undefined1  [16])0x0;
  *(longlong *)pcVar25 = *(longlong *)pcVar25 + -1;
  if (*(longlong *)pcVar25 == 0) {
    (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))();
  }
  pcVar26 = *(code **)(param_1 + 0x138);
  iVar9 = 0x97;
LAB_23e2eda22:
  *(longlong **)(param_1 + 0x138) = plVar12;
  if (pcVar26 == (code *)0x0) {
    apcStack_98[0] = pcVar24;
    auStack_a8 = auVar27;
    pcStack_a0 = pcVar23;
    if (pcVar24 == (code *)0x0) goto LAB_23e2ecde0;
  }
  else {
LAB_23e2eda4a:
    apcStack_98[0] = (code *)0x0;
    _auStack_a8 = (undefined1  [16])0x0;
    *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
    if (*(longlong *)pcVar26 == 0) {
      (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))();
    }
    auStack_a8 = auVar27;
    pcStack_a0 = pcVar23;
    if (pcVar24 == (code *)0x0) {
      apcStack_98[0] = pcVar24;
      if (iVar9 == 0) {
        iVar9 = (int)plVar11[5];
      }
      goto LAB_23e2ecde0;
    }
  }
  if (*(longlong **)(pcVar24 + 0x18) == plVar11) goto LAB_23e2eca0e;
  apcStack_98[0] = pcVar24;
  if (iVar9 == 0) {
    iVar9 = (int)plVar11[5];
  }
  goto LAB_23e2ec968;
}
