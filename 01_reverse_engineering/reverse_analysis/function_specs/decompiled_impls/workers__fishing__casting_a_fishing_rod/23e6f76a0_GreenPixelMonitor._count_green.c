/* ===== 23e6f76a0 workers.fishing.casting_a_fishin:148 ===== */
/* ghidra_name=FUN_23e6f76a0 entry=23e6f76a0 size=3521 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e6f76a0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  code *pcVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong lVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined4 uVar21;
  longlong *plVar22;
  longlong *plStack_80;
  longlong *plStack_78;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar16 = _DAT_23eedb1f0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[2];
  plVar3 = (longlong *)param_3[3];
  plVar4 = (longlong *)param_3[1];
  plVar5 = (longlong *)param_3[4];
  plVar6 = (longlong *)param_3[5];
  if (_DAT_23eedb1f0 == (longlong *)0x0) {
LAB_23e6f7708:
    _DAT_23eedb1f0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb1e8,DAT_23eedb268,0x48);
  }
  else {
    lVar14 = *_DAT_23eedb1f0;
    if (1 < lVar14) {
      *_DAT_23eedb1f0 = lVar14 + -1;
      goto LAB_23e6f7708;
    }
    if (_DAT_23eedb1f0[2] != 0) {
      *_DAT_23eedb1f0 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      goto LAB_23e6f7708;
    }
  }
  plVar9 = _DAT_23eedb1f0;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar16 = _DAT_23eedb1f0 + 9;
  lVar15 = *(longlong *)(lVar14 + 8);
  _DAT_23eedb1f0[0xf] = lVar15;
  *(longlong **)(lVar14 + 8) = plVar16;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar9[0xe] != 0)))) {
    plVar16 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar9[0xe] + 0x10) = plVar16;
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
    }
  }
  *plVar9 = *plVar9 + 1;
  *(undefined4 *)(plVar9 + 8) = 0;
  plVar13 = (longlong *)FUN_23e8c09e0(plVar3,plVar6);
  pcVar11 = _Py_NoneStruct_exref;
  plVar16 = (longlong *)0x0;
  if (plVar13 != (longlong *)0x0) {
    lVar14 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar3,plVar13,_Py_NoneStruct_exref);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
      lVar15 = *(longlong *)(param_1 + 0x10);
      plVar13 = *(longlong **)(lVar15 + 0xe20);
      if (plVar13 == (longlong *)0x0) goto LAB_23e6f7c6e;
LAB_23e6f77de:
      lVar7 = plVar13[3];
      *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
      *(longlong *)(lVar15 + 0xe20) = lVar7;
      *plVar13 = 1;
    }
    else {
      lVar15 = *(longlong *)(param_1 + 0x10);
      plVar13 = *(longlong **)(lVar15 + 0xe20);
      if (plVar13 != (longlong *)0x0) goto LAB_23e6f77de;
LAB_23e6f7c6e:
      plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    pcVar12 = _PyRuntime_exref;
    plVar13[4] = 0;
    lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
    lVar7 = plVar13[-1];
    puVar8 = *(undefined8 **)(lVar15 + 8);
    *puVar8 = plVar13 + -2;
    plVar13[-2] = lVar15;
    plVar13[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar8;
    *(longlong **)(lVar15 + 8) = plVar13 + -2;
    plVar13[3] = lVar14;
    plVar16 = (longlong *)FUN_23e8c09e0(plVar2,plVar5);
    if (plVar16 == (longlong *)0x0) {
      plVar17 = *(longlong **)(param_1 + 0x60);
      plVar19 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      plVar16 = (longlong *)0x0;
      if (*plVar13 == 0) {
        plVar18 = (longlong *)0x0;
        plVar20 = (longlong *)0x0;
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        uVar21 = 0x96;
        plVar13 = DAT_23ed6a4f8;
      }
      else {
        plVar20 = (longlong *)0x0;
        plVar18 = (longlong *)0x0;
        uVar21 = 0x96;
        plVar13 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e6f7d09;
    }
    lVar14 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar2,plVar16,pcVar11);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    plVar13[4] = lVar14;
    plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar4,plVar13);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (plVar16 != (longlong *)0x0) {
      lVar14 = FUN_23e8e1c50();
      if (lVar14 == 0) {
        plVar20 = (longlong *)0x0;
        FUN_23e915740(param_1,&plStack_68,DAT_23eeda460);
        uVar21 = 0x97;
        plVar18 = (longlong *)0x0;
        plVar19 = plStack_58;
        plVar13 = DAT_23ed6a4f8;
        plVar17 = plStack_68;
        plVar10 = plStack_60;
      }
      else {
        plVar13 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23eeda468);
        if (plVar13 == (longlong *)0x0) {
          plVar17 = *(longlong **)(param_1 + 0x60);
          plVar19 = *(longlong **)(param_1 + 0x70);
          plVar20 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar18 = (longlong *)0x0;
          uVar21 = 0x97;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = DAT_23ed6a4f8;
          plVar10 = *(longlong **)(param_1 + 0x68);
        }
        else {
          lVar14 = FUN_23e8e1c50();
          if (lVar14 == 0) {
            FUN_23e915740(param_1,&plStack_68,DAT_23eeda460);
            plVar19 = plStack_58;
            plVar10 = plStack_60;
            plVar17 = plStack_68;
            *plVar13 = *plVar13 + -1;
            plVar18 = (longlong *)0x0;
            if (*plVar13 == 0) {
              plVar20 = (longlong *)0x0;
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              uVar21 = 0x97;
              plVar13 = DAT_23ed6a4f8;
            }
            else {
              plVar20 = (longlong *)0x0;
              uVar21 = 0x97;
              plVar13 = DAT_23ed6a4f8;
            }
          }
          else {
            plVar17 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23eeda538);
            if (plVar17 == (longlong *)0x0) {
              plVar17 = *(longlong **)(param_1 + 0x60);
              plVar19 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar10 = *(longlong **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar13 = *plVar13 + -1;
              plVar20 = (longlong *)0x0;
              if (*plVar13 == 0) {
                plVar18 = (longlong *)0x0;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                uVar21 = 0x97;
                plVar13 = DAT_23ed6a4f8;
              }
              else {
                plVar18 = (longlong *)0x0;
                uVar21 = 0x97;
                plVar13 = DAT_23ed6a4f8;
              }
            }
            else {
              *(undefined4 *)(plVar9 + 5) = 0x97;
              plStack_68 = plVar16;
              plStack_60 = plVar17;
              plVar18 = (longlong *)FUN_23e94ed00(param_1,plVar13,&plStack_68);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (plVar18 == (longlong *)0x0) {
                plVar17 = *(longlong **)(param_1 + 0x60);
                plVar19 = *(longlong **)(param_1 + 0x70);
                plVar20 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0x97;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar13 = DAT_23ed6a4f8;
                plVar10 = *(longlong **)(param_1 + 0x68);
              }
              else {
                lVar14 = FUN_23e8e1c50();
                if (lVar14 == 0) {
                  FUN_23e915740(param_1,&plStack_68,DAT_23eeda460);
                  uVar21 = 0x98;
                  plVar20 = (longlong *)0x0;
                  plVar19 = plStack_58;
                  plVar13 = DAT_23ed6a4f8;
                  plVar17 = plStack_68;
                  plVar10 = plStack_60;
                }
                else {
                  plVar13 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23eeda540);
                  if (plVar13 == (longlong *)0x0) {
                    plVar17 = *(longlong **)(param_1 + 0x60);
                    plVar19 = *(longlong **)(param_1 + 0x70);
                    plVar20 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar21 = 0x98;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar13 = DAT_23ed6a4f8;
                    plVar10 = *(longlong **)(param_1 + 0x68);
                  }
                  else {
                    plVar17 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda548);
                    if (plVar17 == (longlong *)0x0) {
                      plStack_80 = *(longlong **)(param_1 + 0x60);
                      plVar19 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_78 = *(longlong **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        plVar20 = (longlong *)0x0;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                        uVar21 = 0x98;
                        plVar13 = DAT_23ed6a4f8;
                        plVar17 = plStack_80;
                        plVar10 = plStack_78;
                        goto joined_r0x00023e6f7d09;
                      }
                    }
                    else {
                      plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda550);
                      if (plVar19 != (longlong *)0x0) {
                        *(undefined4 *)(plVar9 + 5) = 0x98;
                        plStack_68 = plVar18;
                        plStack_60 = plVar17;
                        plStack_58 = plVar19;
                        plVar20 = (longlong *)FUN_23e956150(param_1,plVar13,&plStack_68);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                        }
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          (**(code **)(plVar19[1] + 0x30))(plVar19);
                        }
                        if (plVar20 == (longlong *)0x0) {
                          plVar17 = *(longlong **)(param_1 + 0x60);
                          plVar19 = *(longlong **)(param_1 + 0x70);
                          uVar21 = 0x98;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = DAT_23ed6a4f8;
                          plVar10 = *(longlong **)(param_1 + 0x68);
                        }
                        else {
                          lVar14 = FUN_23e8e1c50();
                          if (lVar14 == 0) {
                            FUN_23e915740(param_1,&plStack_68,DAT_23eeda460);
                            uVar21 = 0x99;
                            plVar19 = plStack_58;
                            plVar13 = DAT_23ed6a4f8;
                            plVar17 = plStack_68;
                            plVar10 = plStack_60;
                          }
                          else {
                            *(undefined4 *)(plVar9 + 5) = 0x99;
                            lVar14 = FUN_23e915840(param_1,lVar14,_DAT_23eeda558,plVar20);
                            if (lVar14 != 0) {
                              lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                              plVar9 = *(longlong **)(lVar15 + 0x28);
                              plVar13 = (longlong *)plVar9[2];
                              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                   *(undefined8 *)(lVar15 + 0x30);
                              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                              if (plVar13 != (longlong *)0x0) {
                                plVar9[2] = 0;
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))();
                                }
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              plVar9[0xf] = 0;
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                (**(code **)(plVar18[1] + 0x30))(plVar18);
                              }
                              *plVar20 = *plVar20 + -1;
                              if (*plVar20 == 0) {
                                (**(code **)(plVar20[1] + 0x30))(plVar20);
                              }
                              lVar15 = *plVar1;
                              *plVar1 = lVar15 + -1;
                              if (lVar15 + -1 == 0) {
                                (**(code **)(plVar1[1] + 0x30))(plVar1);
                              }
                              lVar15 = *plVar4;
                              *plVar4 = lVar15 + -1;
                              if (lVar15 + -1 == 0) {
                                (**(code **)(plVar4[1] + 0x30))(plVar4);
                              }
                              *plVar2 = *plVar2 + -1;
                              if (*plVar2 == 0) {
                                (**(code **)(plVar2[1] + 0x30))(plVar2);
                              }
                              *plVar3 = *plVar3 + -1;
                              if (*plVar3 == 0) {
                                (**(code **)(plVar3[1] + 0x30))(plVar3);
                              }
                              lVar15 = *plVar5;
                              *plVar5 = lVar15 + -1;
                              if (lVar15 + -1 == 0) {
                                (**(code **)(plVar5[1] + 0x30))(plVar5);
                              }
                              lVar15 = *plVar6;
                              *plVar6 = lVar15 + -1;
                              if (lVar15 + -1 != 0) {
                                return lVar14;
                              }
                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                              return lVar14;
                            }
                            plVar17 = *(longlong **)(param_1 + 0x60);
                            plVar19 = *(longlong **)(param_1 + 0x70);
                            uVar21 = 0x99;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar13 = DAT_23ed6a4f8;
                            plVar10 = *(longlong **)(param_1 + 0x68);
                          }
                        }
                        goto joined_r0x00023e6f7d09;
                      }
                      plStack_80 = *(longlong **)(param_1 + 0x60);
                      plVar19 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_78 = *(longlong **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar17 = *plVar17 + -1;
                      if (*plVar17 == 0) {
                        plVar20 = (longlong *)0x0;
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                        uVar21 = 0x98;
                        plVar13 = DAT_23ed6a4f8;
                        plVar17 = plStack_80;
                        plVar10 = plStack_78;
                        goto joined_r0x00023e6f7d09;
                      }
                    }
                    plVar20 = (longlong *)0x0;
                    uVar21 = 0x98;
                    plVar13 = DAT_23ed6a4f8;
                    plVar17 = plStack_80;
                    plVar10 = plStack_78;
                  }
                }
              }
            }
          }
        }
      }
      goto joined_r0x00023e6f7d09;
    }
  }
  plVar17 = *(longlong **)(param_1 + 0x60);
  plVar19 = *(longlong **)(param_1 + 0x70);
  plVar20 = (longlong *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar18 = (longlong *)0x0;
  uVar21 = 0x96;
  plVar10 = *(longlong **)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar13 = DAT_23ed6a4f8;
joined_r0x00023e6f7d09:
  DAT_23ed6a4f8 = plVar13;
  if (plVar19 == (longlong *)0x0) {
    if (plVar13 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar13;
      *plVar13 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    lVar14 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar21;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar15 = plVar13[-1];
    puVar8 = *(undefined8 **)(lVar14 + 8);
    *puVar8 = plVar13 + -2;
    plVar13[-2] = lVar14;
    plVar13[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar8;
    *(longlong **)(lVar14 + 8) = plVar13 + -2;
    plVar22 = plVar13;
  }
  else {
    plVar22 = plVar19;
    if ((longlong *)plVar19[3] != plVar9) {
      if (plVar13 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar13;
        *plVar13 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar13[3] = (longlong)plVar9;
      *plVar9 = *plVar9 + 1;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar21;
      pcVar11 = _PyRuntime_exref;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
      lVar15 = plVar13[-1];
      puVar8 = *(undefined8 **)(lVar14 + 8);
      *puVar8 = plVar13 + -2;
      plVar13[-2] = lVar14;
      plVar13[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar8;
      lVar15 = *plVar19;
      *(longlong **)(lVar14 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar19;
      plVar22 = plVar13;
      if (lVar15 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
    }
  }
  FUN_23e8bba40(plVar9,"ooooooooo",plVar1,plVar4,plVar2,plVar3,plVar5,plVar6,plVar16,plVar18,plVar20
               );
  if (_DAT_23eedb1f0 == plVar9) {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    _DAT_23eedb1f0 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar14 + 0x28);
  plVar13 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  lVar14 = *plVar1;
  *plVar1 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar14 = *plVar4;
  *plVar4 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar14 = *plVar5;
  *plVar5 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  lVar14 = *plVar6;
  *plVar6 = lVar14 + -1;
  if (lVar14 + -1 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  FUN_23a33aa70(param_1,plVar17,plVar10,plVar22);
  return 0;
}
