/* ===== 23e30b240 ui.garbage_settings_dialog:c1169 ===== */
/* ghidra_name=FUN_23e30b240 entry=23e30b240 size=12172 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e30b240(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  undefined8 uVar23;
  undefined4 uVar24;
  longlong *plVar25;
  longlong *plVar26;
  bool bVar27;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_a0;
  undefined1 auStack_98 [16];
  longlong *aplStack_88 [2];
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  
  plVar8 = _DAT_23eeb03c0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  aplStack_88[0] = (longlong *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  if (_DAT_23eeb03c0 == (longlong *)0x0) {
LAB_23e30b2ab:
    _DAT_23eeb03c0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0460,DAT_23eeb0428,0x60);
  }
  else {
    lVar9 = *_DAT_23eeb03c0;
    if (1 < lVar9) {
      *_DAT_23eeb03c0 = lVar9 + -1;
      goto LAB_23e30b2ab;
    }
    if (_DAT_23eeb03c0[2] != 0) {
      *_DAT_23eeb03c0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e30b2ab;
    }
  }
  plVar3 = _DAT_23eeb03c0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb03c0 + 9;
  lVar22 = *(longlong *)(lVar9 + 8);
  _DAT_23eeb03c0[0xf] = lVar22;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar22 != 0) &&
     (((*(char *)(lVar22 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar22 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar22 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar22 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar22 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  if ((DAT_23ed77850 == 0) && (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0))
  {
LAB_23e30c2a3:
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_NTPATH",
                  "\"Unexpected failure of hard import of \'ntpath\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,_DAT_23eeae5a0);
  if (plVar8 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    aplStack_88[0] = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar24 = 0xbc;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
  }
  else {
    lVar9 = FUN_23e8f82c0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,auStack_98,DAT_23ed6cd80);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
LAB_23e30c3f3:
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar10 = (longlong *)0x0;
    }
    else {
      plVar10 = (longlong *)FUN_23e936ef0(param_1,lVar9);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e936ef0(param_1,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        uVar23 = _DAT_23eeae5b8;
        plVar13 = _DAT_23eeae5b0;
        plVar10 = _DAT_23eeae5a8;
        if (plVar11 == (longlong *)0x0) {
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar10 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          uVar24 = 0xbc;
          plVar11 = (longlong *)0x0;
          goto LAB_23e30bbdd;
        }
        *(undefined4 *)(plVar3 + 5) = 0xbc;
        plStack_70 = plVar10;
        plStack_68 = plVar13;
        uStack_60 = uVar23;
        plStack_78 = plVar11;
        plVar10 = (longlong *)FUN_23e9583d0(param_1,plVar8,&plStack_78);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar10 == (longlong *)0x0) {
          aplStack_88[0] = *(longlong **)(param_1 + 0x70);
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e30c239;
        }
        plVar8 = (longlong *)
                 FUN_23e8d8bc0(*(undefined8 *)(param_1 + 0x10),_DAT_23eeae5c0,_DAT_23eeae5c8,
                               _DAT_23eeae5d0);
        plVar11 = _DAT_23eeae5d8;
        if (*(code **)(_DAT_23eeae5d8[1] + 0xd8) == (code *)0x0) {
          plVar12 = (longlong *)FUN_23a33a530(PySeqIter_Type_exref);
          plVar12[2] = 0;
          *plVar11 = *plVar11 + 1;
          plVar12[3] = (longlong)plVar11;
          lVar9 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar22 = plVar12[-1];
          plVar11 = *(longlong **)(lVar9 + 8);
          *plVar11 = (longlong)(plVar12 + -2);
          plVar12[-2] = lVar9;
          plVar12[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)plVar11;
          *(longlong **)(lVar9 + 8) = plVar12 + -2;
        }
        else {
          plVar12 = (longlong *)(**(code **)(_DAT_23eeae5d8[1] + 0xd8))(_DAT_23eeae5d8);
        }
        plVar11 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar11 == (longlong *)0x0) &&
           (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,2), plVar11 == (longlong *)0x0)
           ) {
          plVar13 = (longlong *)0x0;
        }
        else {
          plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (((plVar13 != (longlong *)0x0) ||
              (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,2),
              plVar13 != (longlong *)0x0)) &&
             (cVar6 = FUN_23a3884a0(param_1,auStack_98,plVar12,2), cVar6 != '\0')) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            plVar12 = (longlong *)FUN_23ebf7180(plVar8);
            if (plVar12 == (longlong *)0x0) {
              auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              aplStack_88[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar24 = 0xc9;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e30bbdd;
            }
            if (plVar1 == (longlong *)0x0) {
              plStack_d0 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
              if (plStack_d0 != (longlong *)0x0) {
                plVar15 = (longlong *)FUN_23a388310(plStack_d0);
                if (plVar15 == (longlong *)0x0) {
                  plStack_c8 = (longlong *)0x0;
                  plStack_c0 = (longlong *)0x0;
                  plStack_d8 = (longlong *)0x0;
                  plStack_a0 = (longlong *)0x0;
                  plVar26 = (longlong *)0x0;
                  plStack_f0 = plVar11;
LAB_23e30d762:
                  plStack_e0 = plStack_c8;
                  plVar14 = *(longlong **)(param_1 + 0x70);
                  pcVar18 = *(code **)(param_1 + 0x60);
                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_e8 = plStack_c0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar11 = plStack_f0;
                  plStack_f8 = plVar26;
                  plStack_f0 = plStack_d8;
                }
                else {
                  plVar16 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                  if ((plVar16 == (longlong *)0x0) &&
                     (plVar16 = (longlong *)FUN_23a3c1b70(param_1,auStack_98),
                     plVar16 == (longlong *)0x0)) {
                    plVar26 = (longlong *)0x0;
                    plStack_c8 = (longlong *)0x0;
                    plStack_c0 = (longlong *)0x0;
                    plStack_d8 = (longlong *)0x0;
                    plStack_a0 = plVar16;
LAB_23e30c8a5:
                    plVar17 = (longlong *)0x0;
                    plVar25 = (longlong *)0x0;
                    plStack_e0 = plStack_c8;
                    plStack_e8 = plStack_c0;
                    plStack_f0 = plStack_d8;
                    plVar16 = (longlong *)0x0;
                    plStack_f8 = plVar26;
                  }
                  else {
                    plStack_f8 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                    if ((plStack_f8 == (longlong *)0x0) &&
                       (plStack_f8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1),
                       plStack_f8 == (longlong *)0x0)) {
                      plVar26 = (longlong *)0x0;
                      plStack_c8 = (longlong *)0x0;
                      plStack_c0 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      plStack_a0 = (longlong *)0x0;
LAB_23e30cb48:
                      plVar17 = (longlong *)0x0;
                      plVar25 = (longlong *)0x0;
                      plStack_e0 = plStack_c8;
                      plStack_e8 = plStack_c0;
                      plStack_f0 = plStack_d8;
                      plStack_f8 = plVar26;
                    }
                    else {
                      plStack_f0 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if ((plStack_f0 == (longlong *)0x0) &&
                         (plStack_f0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2),
                         plStack_f0 == (longlong *)0x0)) {
                        plStack_c8 = (longlong *)0x0;
                        plStack_c0 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plVar26 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
LAB_23e30cc10:
                        plVar17 = (longlong *)0x0;
                        plStack_e0 = plStack_c8;
                        plStack_e8 = plStack_c0;
                        plStack_f0 = plStack_d8;
                        plVar25 = plStack_f8;
                        plStack_f8 = plVar26;
                      }
                      else {
                        cVar6 = FUN_23a3884a0(param_1,auStack_98,plVar15);
                        lVar9 = *plVar15;
                        plVar17 = plStack_f0;
                        if (cVar6 != '\0') {
                          *plVar15 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar15[1] + 0x30))(plVar15);
                          }
                          if (*plVar16 == 0) {
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          if (*plStack_f8 == 0) {
                            (**(code **)(plStack_f8[1] + 0x30))();
                          }
                          if (*plStack_f0 == 0) {
                            (**(code **)(plStack_f0[1] + 0x30))();
                          }
                          if ((DAT_23ed77850 == 0) &&
                             (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0))
                          {
                            DAT_23ed77850 = 0;
                            goto LAB_23e30c2a3;
                          }
                          plVar14 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,_DAT_23eeae5a0);
                          if (plVar14 == (longlong *)0x0) {
                            plStack_c8 = (longlong *)0x0;
                            plStack_c0 = (longlong *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0xca;
                            plStack_70 = plStack_f0;
                            plStack_78 = plVar10;
                            plStack_e8 = (longlong *)FUN_23e94ed00(param_1,plVar14,&plStack_78);
                            lVar9 = *plVar14;
                            *plVar14 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if (plStack_e8 != (longlong *)0x0) {
                              lVar9 = *(longlong *)(DAT_23eeae260 + 0x20);
                              if (*(char *)(lVar9 + 10) == '\0') {
                                plStack_c8 = (longlong *)FUN_23a37a020(DAT_23eeae260,_DAT_23eeae5e8)
                                ;
                                if (plStack_c8 == (longlong *)0x0) goto LAB_23e30de1b;
                                plStack_c8 = (longlong *)*plStack_c8;
LAB_23e30de0c:
                                if (plStack_c8 == (longlong *)0x0) goto LAB_23e30de1b;
LAB_23e30d315:
                                *(undefined4 *)(plVar3 + 5) = 0xcd;
                                plStack_70 = plStack_f8;
                                plStack_78 = plVar16;
                                plStack_68 = plStack_e8;
                                plStack_e0 = (longlong *)
                                             FUN_23e956150(param_1,plStack_c8,&plStack_78);
                                if (plStack_e0 == (longlong *)0x0) {
                                  plStack_c8 = (longlong *)0x0;
LAB_23e30d9a4:
                                  plStack_f0 = plVar17;
                                  pcVar18 = *(code **)(param_1 + 0x60);
                                  plVar14 = *(longlong **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  uVar24 = 0xcd;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_e0 = plStack_c8;
                                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                                }
                                else {
                                  auStack_98._8_8_ =
                                       PyUnicode_FromFormat
                                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                                  ,_DAT_23eeae5f0);
                                  auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                                  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
                                  aplStack_88[0] = (longlong *)0x0;
                                  if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
                                    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
                                  }
                                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
                                  uVar24 = 0xce;
                                  plVar14 = aplStack_88[0];
                                  pcVar18 = (code *)auStack_98._0_8_;
                                  uVar23 = auStack_98._8_8_;
                                }
                              }
                              else {
                                iVar7 = *(int *)(lVar9 + 0xc);
                                if (*(int *)(lVar9 + 0xc) == 0) {
                                  *(int *)(lVar9 + 0xc) = DAT_23ec14e8c;
                                  iVar7 = DAT_23ec14e8c;
                                  DAT_23ec14e8c = DAT_23ec14e8c + 1;
                                }
                                if (_DAT_23ec14e74 != iVar7) {
                                  _DAT_23ec14e74 = iVar7;
                                  _DAT_23eeb03b8 =
                                       FUN_23e8cbd60(lVar9,_DAT_23eeae5e8,
                                                     *(undefined8 *)(_DAT_23eeae5e8 + 0x18));
                                }
                                if (-1 < _DAT_23eeb03b8) {
                                  lVar22 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                                  plStack_c8 = *(longlong **)(lVar22 + 8 + _DAT_23eeb03b8 * 0x10);
                                  if (plStack_c8 != (longlong *)0x0) goto LAB_23e30d315;
                                  _DAT_23eeb03b8 =
                                       FUN_23e8cbd60(lVar9,_DAT_23eeae5e8,
                                                     *(undefined8 *)(_DAT_23eeae5e8 + 0x18));
                                  if (-1 < _DAT_23eeb03b8) {
                                    plStack_c8 = *(longlong **)(lVar22 + 8 + _DAT_23eeb03b8 * 0x10);
                                    goto LAB_23e30de0c;
                                  }
                                }
LAB_23e30de1b:
                                plStack_c8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeae5e8)
                                ;
                                if (plStack_c8 != (longlong *)0x0) {
                                  plStack_c8 = (longlong *)*plStack_c8;
                                  if (plStack_c8 != (longlong *)0x0) goto LAB_23e30d315;
                                  plStack_c8 = (longlong *)0x0;
                                }
LAB_23e30bff0:
                                plStack_f0 = plVar17;
                                plStack_e0 = plStack_c8;
                                FUN_23e915740(param_1,auStack_98,_DAT_23eeae5e8);
                                uVar24 = 0xcd;
                                plVar14 = aplStack_88[0];
                                pcVar18 = (code *)auStack_98._0_8_;
                                uVar23 = auStack_98._8_8_;
                              }
                              goto LAB_23e30c046;
                            }
                            plStack_c8 = (longlong *)0x0;
                            plStack_c0 = (longlong *)0x0;
                          }
LAB_23e30cee8:
                          plStack_f0 = plVar17;
                          pcVar18 = *(code **)(param_1 + 0x60);
                          plVar14 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          uVar24 = 0xca;
                          plStack_e0 = plStack_c8;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_e8 = plStack_c0;
                          uVar23 = *(undefined8 *)(param_1 + 0x68);
                          goto LAB_23e30c046;
                        }
                        plVar26 = (longlong *)0x0;
                        plStack_c8 = (longlong *)0x0;
                        plStack_c0 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
LAB_23e30d851:
                        plStack_f0 = plVar17;
                        plStack_e0 = plStack_c8;
                        plStack_e8 = plStack_c0;
                        plVar17 = plStack_f0;
                        plVar25 = plStack_f8;
                        plStack_f8 = plVar26;
                        plStack_f0 = plStack_d8;
                      }
                    }
                  }
                  plVar14 = aplStack_88[0];
                  pcVar18 = (code *)auStack_98._0_8_;
                  uVar23 = auStack_98._8_8_;
                  aplStack_88[0] = (longlong *)0x0;
                  auStack_98 = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  aplStack_88[0] = (longlong *)0x0;
                  auStack_98 = (undefined1  [16])0x0;
                  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
                    (**(code **)(plVar25[1] + 0x30))(plVar25);
                  }
                  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                }
                uVar24 = 0xc9;
                plVar16 = plStack_a0;
                goto LAB_23e30c046;
              }
              plStack_d0 = (longlong *)0x0;
              plVar26 = (longlong *)0x0;
              plStack_c8 = (longlong *)0x0;
              plStack_c0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_a0 = (longlong *)0x0;
LAB_23e30d460:
              cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
              if (cVar6 != '\0') {
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar3 = *(longlong **)(lVar9 + 0x28);
                plVar14 = (longlong *)plVar3[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                if (plVar14 != (longlong *)0x0) {
                  plVar3[2] = 0;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))();
                  }
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                plVar3[0xf] = 0;
                if ((plStack_d0 != (longlong *)0x0) &&
                   (*plStack_d0 = *plStack_d0 + -1, *plStack_d0 == 0)) {
                  (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                }
                lVar9 = *plVar12;
                *plVar12 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                pcVar18 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if ((plStack_a0 != (longlong *)0x0) &&
                   (lVar9 = *plStack_a0, *plStack_a0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
                }
                if ((plVar26 != (longlong *)0x0) && (*plVar26 = *plVar26 + -1, *plVar26 == 0)) {
                  (**(code **)(plVar26[1] + 0x30))(plVar26);
                }
                if ((plStack_d8 != (longlong *)0x0) &&
                   (lVar9 = *plStack_d8, *plStack_d8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                }
                if ((plStack_c0 != (longlong *)0x0) &&
                   (lVar9 = *plStack_c0, *plStack_c0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                }
                if ((plStack_c8 != (longlong *)0x0) &&
                   (lVar9 = *plStack_c8, *plStack_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                }
                lVar9 = *plVar1;
                *plVar1 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                lVar9 = *plVar2;
                *plVar2 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                  return pcVar18;
                }
                return pcVar18;
              }
              plVar14 = *(longlong **)(param_1 + 0x70);
              pcVar18 = *(code **)(param_1 + 0x60);
              uVar23 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              aplStack_88[0] = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              auStack_98 = (undefined1  [16])0x0;
              plStack_f8 = plVar26;
              if (plStack_d0 != (longlong *)0x0) {
                uVar24 = 0xc9;
                plStack_e0 = plStack_c8;
                plStack_e8 = plStack_c0;
                plStack_f0 = plStack_d8;
                plVar16 = plStack_a0;
                goto LAB_23e30c046;
              }
              plStack_e0 = plStack_c8;
              uVar24 = 0xc9;
              plStack_e8 = plStack_c0;
              plStack_f0 = plStack_d8;
            }
            else {
              plStack_c8 = (longlong *)0x0;
              plStack_c0 = (longlong *)0x0;
              plStack_a0 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              plStack_d0 = (longlong *)0x0;
              plVar26 = (longlong *)0x0;
              plStack_f0 = plVar11;
              do {
                plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))();
                plVar11 = plStack_f0;
                if (plVar14 == (longlong *)0x0) goto LAB_23e30d460;
                if ((plStack_d0 != (longlong *)0x0) &&
                   (*plStack_d0 = *plStack_d0 + -1, *plStack_d0 == 0)) {
                  (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                }
                plVar15 = (longlong *)FUN_23a388310(plVar14);
                plStack_d0 = plVar14;
                if (plVar15 == (longlong *)0x0) goto LAB_23e30d762;
                plVar16 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                if ((plVar16 == (longlong *)0x0) &&
                   (plVar16 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0),
                   plVar16 == (longlong *)0x0)) goto LAB_23e30c8a5;
                plStack_f8 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                if ((plStack_f8 == (longlong *)0x0) &&
                   (plStack_f8 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1),
                   plStack_f8 == (longlong *)0x0)) goto LAB_23e30cb48;
                plVar17 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                if ((plVar17 == (longlong *)0x0) &&
                   (plVar17 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2),
                   plVar17 == (longlong *)0x0)) goto LAB_23e30cc10;
                cVar6 = FUN_23a3884a0(param_1,auStack_98,plVar15,3);
                lVar9 = *plVar15;
                if (cVar6 == '\0') goto LAB_23e30d851;
                *plVar15 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                lVar9 = *plVar16;
                *plVar16 = lVar9 + 1;
                if (plStack_a0 != (longlong *)0x0) {
                  *plStack_a0 = *plStack_a0 + -1;
                  if (*plStack_a0 == 0) {
                    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
                    lVar9 = *plVar16 + -1;
                  }
                  else {
                    lVar9 = *plVar16 + -1;
                  }
                }
                *plVar16 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                lVar9 = *plStack_f8;
                *plStack_f8 = lVar9 + 1;
                if (plVar26 != (longlong *)0x0) {
                  *plVar26 = *plVar26 + -1;
                  if (*plVar26 == 0) {
                    (**(code **)(plVar26[1] + 0x30))(plVar26);
                    lVar9 = *plStack_f8 + -1;
                  }
                  else {
                    lVar9 = *plStack_f8 + -1;
                  }
                }
                *plStack_f8 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
                }
                lVar9 = *plVar17;
                *plVar17 = lVar9 + 1;
                if (plStack_d8 != (longlong *)0x0) {
                  *plStack_d8 = *plStack_d8 + -1;
                  if (*plStack_d8 == 0) {
                    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                    lVar9 = *plVar17 + -1;
                  }
                  else {
                    lVar9 = *plVar17 + -1;
                  }
                }
                *plVar17 = lVar9;
                if (lVar9 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                if ((DAT_23ed77850 == 0) &&
                   (DAT_23ed77850 = PyImport_ImportModule("ntpath"), DAT_23ed77850 == 0)) {
                  DAT_23ed77850 = 0;
                  goto LAB_23e30c2a3;
                }
                plVar14 = (longlong *)FUN_23e8bc2f0(DAT_23ed77850,_DAT_23eeae5a0);
                if (plVar14 == (longlong *)0x0) goto LAB_23e30cee8;
                *(undefined4 *)(plVar3 + 5) = 0xca;
                plStack_78 = plVar10;
                plStack_70 = plVar17;
                plStack_e8 = (longlong *)FUN_23e94ed00(param_1,plVar14,&plStack_78);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (plStack_e8 == (longlong *)0x0) goto LAB_23e30cee8;
                if ((plStack_c0 != (longlong *)0x0) &&
                   (lVar9 = *plStack_c0, *plStack_c0 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                }
                lVar9 = *(longlong *)(DAT_23eeae260 + 0x20);
                if (*(char *)(lVar9 + 10) == '\0') {
                  plVar14 = (longlong *)FUN_23a37a020(DAT_23eeae260,_DAT_23eeae5e8);
                  if (plVar14 == (longlong *)0x0) goto LAB_23e30bf89;
                  lVar22 = *plVar14;
LAB_23e30cc80:
                  if (lVar22 == 0) goto LAB_23e30bf89;
                }
                else {
                  iVar7 = *(int *)(lVar9 + 0xc);
                  if (*(int *)(lVar9 + 0xc) == 0) {
                    *(int *)(lVar9 + 0xc) = DAT_23ec14e8c;
                    iVar7 = DAT_23ec14e8c;
                    DAT_23ec14e8c = DAT_23ec14e8c + 1;
                  }
                  if (_DAT_23ec14e74 != iVar7) {
                    _DAT_23ec14e74 = iVar7;
                    _DAT_23eeb03b8 =
                         FUN_23e8cbd60(lVar9,_DAT_23eeae5e8,*(undefined8 *)(_DAT_23eeae5e8 + 0x18));
                  }
                  if (-1 < _DAT_23eeb03b8) {
                    lVar21 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                    lVar22 = *(longlong *)(lVar21 + 8 + _DAT_23eeb03b8 * 0x10);
                    if (lVar22 != 0) goto LAB_23e30b821;
                    _DAT_23eeb03b8 =
                         FUN_23e8cbd60(lVar9,_DAT_23eeae5e8,*(undefined8 *)(_DAT_23eeae5e8 + 0x18));
                    if (-1 < _DAT_23eeb03b8) {
                      lVar22 = *(longlong *)(lVar21 + 8 + _DAT_23eeb03b8 * 0x10);
                      goto LAB_23e30cc80;
                    }
                  }
LAB_23e30bf89:
                  plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeae5e8);
                  if ((plVar14 == (longlong *)0x0) || (lVar22 = *plVar14, lVar22 == 0))
                  goto LAB_23e30bff0;
                }
LAB_23e30b821:
                *(undefined4 *)(plVar3 + 5) = 0xcd;
                plStack_78 = plVar16;
                plStack_70 = plStack_f8;
                plStack_68 = plStack_e8;
                plStack_e0 = (longlong *)FUN_23e956150(param_1,lVar22,&plStack_78);
                if (plStack_e0 == (longlong *)0x0) goto LAB_23e30d9a4;
                if ((plStack_c8 != (longlong *)0x0) &&
                   (lVar9 = *plStack_c8, *plStack_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
                  (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                }
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeae440);
                if (plVar14 == (longlong *)0x0) {
LAB_23e30cf40:
                  uVar24 = 0xce;
                  plVar14 = *(longlong **)(param_1 + 0x70);
                  pcVar18 = *(code **)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                  plStack_f0 = plVar17;
                  goto LAB_23e30c046;
                }
                cVar6 = FUN_23a39bc50(param_1,plVar14,plVar16,plStack_e0);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (cVar6 == '\0') goto LAB_23e30cf40;
                uVar23 = _DAT_23eeae5f8;
                if (plVar2 == (longlong *)0x0) goto LAB_23e30da3b;
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eeae388);
                if (plVar14 == (longlong *)0x0) {
LAB_23e30d000:
                  uVar24 = 0xd0;
                  plVar14 = *(longlong **)(param_1 + 0x70);
                  pcVar18 = *(code **)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                  plStack_f0 = plVar17;
                  goto LAB_23e30c046;
                }
                if (plStack_f0 == (longlong *)0x0) {
                  *plVar14 = *plVar14 + -1;
                  uVar23 = _DAT_23eeae600;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    uVar23 = _DAT_23eeae600;
                  }
LAB_23e30da3b:
                  auStack_98._8_8_ =
                       PyUnicode_FromFormat
                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                  ,uVar23);
                  auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
                  aplStack_88[0] = (longlong *)0x0;
                  if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
                    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
                  }
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
                  uVar24 = 0xd0;
                  plVar14 = aplStack_88[0];
                  pcVar18 = (code *)auStack_98._0_8_;
                  uVar23 = auStack_98._8_8_;
                  plStack_f0 = plVar17;
                  goto LAB_23e30c046;
                }
                if (plVar13 == (longlong *)0x0) {
                  *plVar14 = *plVar14 + -1;
                  uVar23 = _DAT_23eeae608;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    uVar23 = _DAT_23eeae608;
                  }
                  goto LAB_23e30da3b;
                }
                *(undefined4 *)(plVar3 + 5) = 0xd0;
                plStack_70 = plStack_f0;
                plStack_78 = plStack_e0;
                plStack_68 = plVar13;
                plVar15 = (longlong *)FUN_23e956150(param_1,plVar14,&plStack_78);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (plVar15 == (longlong *)0x0) goto LAB_23e30d000;
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                plStack_78 = plVar13;
                if ((code *)plVar13[1] != PyLong_Type_exref) {
                  cVar6 = FUN_23e8c7160(&plStack_78);
                  plVar14 = plStack_78;
                  if (cVar6 != '\0') goto LAB_23e30b9d5;
LAB_23e30d8e4:
                  uVar24 = 0xd2;
                  plVar14 = *(longlong **)(param_1 + 0x70);
                  pcVar18 = *(code **)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                  plStack_f0 = plVar17;
                  goto LAB_23e30c046;
                }
                lVar9 = plVar13[2];
                lVar22 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
                lVar21 = *plVar13;
                if (lVar9 < 0) {
                  lVar19 = -lVar9;
                  lVar20 = lVar22;
                  if (lVar9 == -1 || lVar19 < 1) {
                    if (lVar22 < 0) {
                      lVar20 = -lVar22;
                      if (lVar22 == -1 || lVar20 < 1) {
                        iVar7 = -(int)plVar13[3];
                        goto LAB_23e30dc4e;
                      }
                      if (lVar21 == 1) goto LAB_23e30ddca;
LAB_23e30d0a6:
                      plVar14 = (longlong *)
                                FUN_23e8be550(plVar13 + 3,lVar19,DAT_23ed6ccf8 + 0x18,lVar20);
                      plVar14[2] = -plVar14[2];
                      goto LAB_23e30c39d;
                    }
                    if (lVar22 < 2) {
                      iVar7 = -(int)plVar13[3];
                      goto LAB_23e30d8b5;
                    }
                    if (lVar21 != 1) goto LAB_23e30c826;
                  }
                  else {
                    lVar20 = -lVar22;
                    if (-lVar22 < 0) {
                      lVar20 = lVar22;
                    }
                    if (lVar21 != 1) {
                      if (-1 < lVar22) {
LAB_23e30c826:
                        plVar14 = (longlong *)
                                  FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar20,plVar13 + 3,lVar19);
                        goto LAB_23e30c39d;
                      }
                      goto LAB_23e30d0a6;
                    }
                    if (lVar22 < 0) {
LAB_23e30ddca:
                      plVar14 = (longlong *)FUN_23e8be680(plVar13,DAT_23ed6ccf8 + 0x18,lVar20);
                      lVar9 = -plVar14[2];
                      if (-1 < lVar9) {
                        lVar9 = plVar14[2];
                      }
                      plVar14[2] = lVar9;
                      goto LAB_23e30b9d5;
                    }
                  }
                  plVar14 = (longlong *)
                            FUN_23e8beb80(plVar13,DAT_23ed6ccf8 + 0x18,lVar20,0xffffffff);
                }
                else if (lVar9 < 2) {
                  if (lVar22 < 0) {
                    lVar20 = -lVar22;
                    if (lVar22 != -1 && 0 < lVar20) {
                      if (lVar21 == 1) goto LAB_23e30ce96;
                      goto LAB_23e30ccf0;
                    }
                    iVar7 = 0;
                    if (lVar9 != 0) {
                      iVar7 = (int)plVar13[3];
                    }
LAB_23e30dc4e:
                    iVar7 = iVar7 - *(int *)(DAT_23ed6ccf8 + 0x18);
                  }
                  else {
                    if (1 < lVar22) {
                      if (lVar21 == 1) goto LAB_23e30c7e4;
                      goto LAB_23e30c386;
                    }
                    iVar7 = 0;
                    if (lVar9 != 0) {
                      iVar7 = (int)plVar13[3];
                    }
LAB_23e30d8b5:
                    if (lVar22 != 0) {
                      iVar7 = iVar7 + *(int *)(DAT_23ed6ccf8 + 0x18);
                    }
                  }
                  if (lVar21 != 1) {
                    plVar14 = (longlong *)FUN_23e8bb5f0();
                    goto LAB_23e30c39d;
                  }
                  FUN_23e8be320(&plStack_78,iVar7);
                  plVar14 = plStack_78;
                }
                else {
                  lVar20 = -lVar22;
                  if (-lVar22 < 0) {
                    lVar20 = lVar22;
                  }
                  if (lVar21 == 1) {
                    bVar27 = lVar22 < 0;
                    lVar22 = lVar20;
                    if (bVar27) {
LAB_23e30ce96:
                      plVar14 = (longlong *)FUN_23e8beb80(plVar13,DAT_23ed6ccf8 + 0x18,lVar20,1);
                    }
                    else {
LAB_23e30c7e4:
                      plVar14 = (longlong *)FUN_23e8be680(plVar13,DAT_23ed6ccf8 + 0x18,lVar22);
                    }
                  }
                  else {
                    bVar27 = lVar22 < 0;
                    lVar22 = lVar20;
                    if (bVar27) {
LAB_23e30ccf0:
                      plVar14 = (longlong *)
                                FUN_23e8be900(plVar13 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar20);
                    }
                    else {
LAB_23e30c386:
                      plVar14 = (longlong *)
                                FUN_23e8be550(plVar13 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar22);
                      if (plVar14 == (longlong *)0x0) goto LAB_23e30d8e4;
                    }
LAB_23e30c39d:
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                  }
                }
LAB_23e30b9d5:
                plVar13 = plVar14;
                iVar7 = FUN_23e97d380(plVar13,_DAT_23eeae610);
                plVar14 = DAT_23ed6ccf0;
                if (iVar7 == -1) {
                  uVar24 = 199;
                  plVar14 = *(longlong **)(param_1 + 0x70);
                  pcVar18 = *(code **)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar23 = *(undefined8 *)(param_1 + 0x68);
                  plStack_f0 = plVar17;
                  goto LAB_23e30c046;
                }
                plVar15 = plStack_f0;
                if (iVar7 == 1) {
                  *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  plStack_78 = plStack_f0;
                  plVar13 = plVar14;
                  if ((code *)plStack_f0[1] == PyLong_Type_exref) {
                    lVar9 = plStack_f0[2];
                    lVar22 = *plStack_f0;
                    lVar21 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
                    if (lVar9 < 0) {
                      lVar20 = -lVar9;
                      if (lVar9 == -1 || lVar20 < 1) {
                        if (lVar21 < 0) {
                          lVar9 = -lVar21;
                          if (lVar21 == -1 || lVar9 < 1) {
                            iVar7 = -(int)plStack_f0[3];
                            goto LAB_23e30df5c;
                          }
                          if (lVar22 != 1) goto LAB_23e30df30;
LAB_23e30dd63:
                          plVar15 = (longlong *)FUN_23e8be680(plStack_f0,DAT_23ed6ccf8 + 0x18,lVar9)
                          ;
                          lVar9 = -plVar15[2];
                          if (-1 < lVar9) {
                            lVar9 = plVar15[2];
                          }
                          plVar15[2] = lVar9;
                          goto LAB_23e30b9f6;
                        }
                        if (lVar21 < 2) {
                          iVar7 = -(int)plStack_f0[3];
                          goto LAB_23e30de6d;
                        }
                        lVar9 = lVar21;
                        if (lVar22 != 1) goto LAB_23e30d7f0;
                      }
                      else {
                        lVar9 = -lVar21;
                        if (-lVar21 < 0) {
                          lVar9 = lVar21;
                        }
                        if (lVar22 != 1) {
                          bVar27 = lVar21 < 0;
                          lVar21 = lVar9;
                          if (bVar27) {
LAB_23e30df30:
                            plVar15 = (longlong *)
                                      FUN_23e8be550(plStack_f0 + 3,lVar20,DAT_23ed6ccf8 + 0x18,lVar9
                                                   );
                            plVar15[2] = -plVar15[2];
                          }
                          else {
LAB_23e30d7f0:
                            plVar15 = (longlong *)
                                      FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar21,plStack_f0 + 3,
                                                    lVar20);
                          }
                          goto LAB_23e30caaa;
                        }
                        if (lVar21 < 0) goto LAB_23e30dd63;
                      }
                      plVar15 = (longlong *)
                                FUN_23e8beb80(plStack_f0,DAT_23ed6ccf8 + 0x18,lVar9,0xffffffff);
                    }
                    else {
                      if (lVar9 < 2) {
                        if (lVar21 < 0) {
                          lVar20 = -lVar21;
                          if (lVar21 != -1 && 0 < lVar20) {
                            if (lVar22 != 1) goto LAB_23e30cfed;
                            goto LAB_23e30dc83;
                          }
                          iVar7 = 0;
                          if (lVar9 != 0) {
                            iVar7 = (int)plStack_f0[3];
                          }
LAB_23e30df5c:
                          iVar7 = iVar7 - *(int *)(DAT_23ed6ccf8 + 0x18);
                        }
                        else {
                          if (1 < lVar21) {
                            if (lVar22 == 1) goto LAB_23e30df90;
                            goto LAB_23e30ca96;
                          }
                          iVar7 = 0;
                          if (lVar9 != 0) {
                            iVar7 = (int)plStack_f0[3];
                          }
LAB_23e30de6d:
                          if (lVar21 != 0) {
                            iVar7 = iVar7 + *(int *)(DAT_23ed6ccf8 + 0x18);
                          }
                        }
                        if (lVar22 == 1) {
                          FUN_23e8be320(&plStack_78,iVar7);
                          goto LAB_23e30c476;
                        }
                        plVar15 = (longlong *)FUN_23e8bb5f0();
                      }
                      else {
                        lVar20 = -lVar21;
                        if (-lVar21 < 0) {
                          lVar20 = lVar21;
                        }
                        if (lVar22 == 1) {
                          bVar27 = -1 < lVar21;
                          lVar21 = lVar20;
                          if (bVar27) {
LAB_23e30df90:
                            plVar15 = (longlong *)
                                      FUN_23e8be680(plStack_f0,DAT_23ed6ccf8 + 0x18,lVar21);
                            goto LAB_23e30b9f6;
                          }
LAB_23e30dc83:
                          plVar15 = (longlong *)
                                    FUN_23e8beb80(plStack_f0,DAT_23ed6ccf8 + 0x18,lVar20,1);
                          goto LAB_23e30b9f6;
                        }
                        bVar27 = lVar21 < 0;
                        lVar21 = lVar20;
                        if (bVar27) {
LAB_23e30cfed:
                          plVar15 = (longlong *)
                                    FUN_23e8be900(plStack_f0 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar20);
                          goto LAB_23e30caaa;
                        }
LAB_23e30ca96:
                        plVar15 = (longlong *)
                                  FUN_23e8be550(plStack_f0 + 3,lVar9,DAT_23ed6ccf8 + 0x18,lVar21);
                        if (plVar15 == (longlong *)0x0) goto LAB_23e30de8d;
                      }
LAB_23e30caaa:
                      lVar9 = *plStack_f0;
                      *plStack_f0 = lVar9 + -1;
                      if (lVar9 + -1 == 0) {
                        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
                      }
                    }
                  }
                  else {
                    cVar6 = FUN_23e8c7160(&plStack_78,DAT_23ed6ccf8);
                    if (cVar6 == '\0') {
LAB_23e30de8d:
                      uVar24 = 0xd5;
                      plVar14 = *(longlong **)(param_1 + 0x70);
                      pcVar18 = *(code **)(param_1 + 0x60);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar23 = *(undefined8 *)(param_1 + 0x68);
                      plStack_f0 = plVar17;
                      goto LAB_23e30c046;
                    }
LAB_23e30c476:
                    plStack_f0 = plStack_78;
                    plVar15 = plStack_f0;
                  }
                }
LAB_23e30b9f6:
                plStack_f0 = plVar15;
                lVar9 = *(longlong *)(param_1 + 0x10);
                if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                     (*(int *)(lVar9 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0))
                   && (pcVar18 = *(code **)(param_1 + 0x60), pcVar18 != (code *)0x0))
                goto LAB_23e30c614;
                if (*(int *)(lVar9 + 0x68) == 0) {
                  plVar11 = *(longlong **)(param_1 + 0x90);
                }
                else {
                  PyEval_SaveThread();
                  PyEval_AcquireThread(param_1);
                  plVar11 = *(longlong **)(param_1 + 0x90);
                }
                plStack_a0 = plVar16;
                plStack_d8 = plVar17;
                plVar26 = plStack_f8;
                plStack_c8 = plStack_e0;
                plStack_c0 = plStack_e8;
              } while (plVar11 == (longlong *)0x0);
              plVar14 = *(longlong **)(param_1 + 0x60);
              plVar15 = *(longlong **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x90) = 0;
              plVar26 = *(longlong **)(param_1 + 0x70);
              *(longlong **)(param_1 + 0x60) = plVar11;
              *plVar11 = *plVar11 + 1;
              *(undefined8 *)(param_1 + 0x68) = 0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if ((plVar26 != (longlong *)0x0) && (*plVar26 = *plVar26 + -1, *plVar26 == 0)) {
                (**(code **)(plVar26[1] + 0x30))(plVar26);
              }
              pcVar18 = *(code **)(param_1 + 0x60);
LAB_23e30c614:
              plVar14 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar24 = 0xc9;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = plStack_f0;
              uVar23 = *(undefined8 *)(param_1 + 0x68);
              plStack_f0 = plVar17;
LAB_23e30c046:
              aplStack_88[0] = (longlong *)0x0;
              auStack_98 = (undefined1  [16])0x0;
              lVar9 = *plStack_d0;
              *plStack_d0 = lVar9 + -1;
              plStack_a0 = plVar16;
              if (lVar9 + -1 == 0) {
                (**(code **)(plStack_d0[1] + 0x30))();
              }
            }
            lVar9 = *plVar12;
            *plVar12 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            auStack_98._8_8_ = uVar23;
            auStack_98._0_8_ = pcVar18;
            plVar12 = DAT_23ed6a4f8;
            goto joined_r0x00023e30bbe0;
          }
        }
        plVar14 = aplStack_88[0];
        auVar5 = auStack_98;
        aplStack_88[0] = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        aplStack_88[0] = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uVar24 = 0xc6;
        auStack_98 = auVar5;
        aplStack_88[0] = plVar14;
        goto LAB_23e30bbdd;
      }
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_88[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      plVar10 = (longlong *)0x0;
      if (*plVar8 == 0) goto LAB_23e30c3f3;
    }
LAB_23e30c239:
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar24 = 0xbc;
  }
LAB_23e30bbdd:
  plStack_e0 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_f0 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  plStack_a0 = (longlong *)0x0;
  plVar12 = DAT_23ed6a4f8;
  plVar14 = aplStack_88[0];
joined_r0x00023e30bbe0:
  DAT_23ed6a4f8 = plVar12;
  aplStack_88[0] = plVar14;
  if (plVar14 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar24;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar22 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar14 = plVar12;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))(aplStack_88[0]);
    }
  }
  else if ((longlong *)plVar14[3] != plVar3) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar12[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar9 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar24;
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar22 = plVar12[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar12[2] = (longlong)plVar14;
    *plVar14 = *plVar14 + 1;
    plVar14 = plVar12;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))();
    }
  }
  aplStack_88[0] = plVar14;
  FUN_23e8bba40(plVar3,"ooooooNooooo",plVar1,plVar2,plVar10,plVar8,plVar11,plVar13,0,plStack_a0,
                plStack_f8,plStack_f0,plStack_e8,plStack_e0);
  if (_DAT_23eeb03c0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb03c0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar9 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar12 = aplStack_88[0];
  auVar5 = auStack_98;
  plVar3[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  aplStack_88[0] = (longlong *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_a0 != (longlong *)0x0) && (*plStack_a0 = *plStack_a0 + -1, *plStack_a0 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar9 = *plStack_f8, *plStack_f8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar9 = *plStack_f0, *plStack_f0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar9 = *plStack_e8, *plStack_e8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar9 = *plStack_e0, *plStack_e0 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  auStack_98 = auVar5;
  aplStack_88[0] = plVar12;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar9 = *plVar2;
  *plVar2 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,aplStack_88[0]);
  return (code *)0x0;
}
