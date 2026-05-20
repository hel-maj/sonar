/* ===== 23e117620 telegram.handlers.fishing_handle:154 ===== */
/* ghidra_name=FUN_23e117620 entry=23e117620 size=3979 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e117620(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong *plStack_a0;
  longlong *plStack_98;
  undefined8 uStack_90;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar14 = DAT_23ed6a4e0;
  plVar1 = (longlong *)*param_3;
  lVar7 = param_3[1];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar14 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar13 = DAT_23ed6a4e0;
  }
  else {
    plVar13 = (longlong *)*DAT_23ed6a4e0;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    plVar8 = plVar13;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar8;
  }
  pcVar5 = _PyRuntime_exref;
  plVar14[2] = lVar7;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar14[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar14 + -2;
  plVar14[-2] = lVar7;
  plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar14 + -2;
  if (plVar13 == (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    DAT_23ed6a4e0 = (longlong *)*plVar13;
    *plVar13 = 1;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar5 = _PyRuntime_exref;
  plVar13[2] = 0;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar13[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar13 + -2;
  plVar13[-2] = lVar7;
  plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar13 + -2;
  uVar6 = FUN_23e8d7870(param_1,_DAT_23eea94e0);
  uVar4 = DAT_23eeab180;
  *plVar14 = *plVar14 + 1;
  plStack_68 = plVar14;
  lVar7 = FUN_23e93e1e0(FUN_23e118620,DAT_23eea94e8,DAT_23eea94f0,DAT_23eeab100,0,uVar6,uVar4,0,
                        &plStack_68,1);
  plVar8 = _DAT_23eeab128;
  plVar13[2] = lVar7;
  if (plVar8 == (longlong *)0x0) {
LAB_23e1177bd:
    plVar8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab120,DAT_23eeab180,0x30);
    _DAT_23eeab128 = plVar8;
  }
  else {
    lVar7 = *plVar8;
    if (1 < lVar7) {
      *plVar8 = lVar7 + -1;
      goto LAB_23e1177bd;
    }
    if (plVar8[2] != 0) {
      *plVar8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e1177bd;
    }
  }
  lVar7 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(lVar7 + 8);
  plVar8[0xf] = lVar2;
  *(longlong **)(lVar7 + 8) = plVar8 + 9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar8[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  uVar4 = _DAT_23eea94f8;
  *(undefined4 *)(plVar8 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar4);
  if (plVar9 == (longlong *)0x0) goto LAB_23e1181b0;
  lVar7 = FUN_23e900ab0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&plStack_68,DAT_23eea9500);
    plStack_98 = plStack_68;
    uStack_90 = uStack_60;
    plVar10 = plStack_58;
LAB_23e117f97:
    *plVar9 = *plVar9 + -1;
    uVar15 = 0xa2;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar15 = 0xa2;
    }
  }
  else {
    plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea9508);
    if (plVar10 == (longlong *)0x0) {
LAB_23e117f70:
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e117f97;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea9510);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e117f70;
    *(undefined4 *)(plVar8 + 5) = 0xa2;
    plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar11,_DAT_23eea9518);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23e117f70;
    *(undefined4 *)(plVar8 + 5) = 0xa2;
    plVar11 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    uVar4 = DAT_23eea9520;
    if (plVar11 == (longlong *)0x0) {
LAB_23e1181b0:
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0xa2;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      lVar7 = FUN_23e900960();
      if (lVar7 != 0) {
        uVar6 = _PyDict_NewPresized(2);
        PyDict_SetItem(uVar6,uVar4,lVar7);
        pcVar5 = _Py_NoneStruct_exref;
        PyDict_SetItem(uVar6,_DAT_23eea9530,_Py_NoneStruct_exref);
        *plVar13 = *plVar13 + 1;
        plStack_68 = plVar13;
        plVar9 = (longlong *)
                 FUN_23e93e1e0(FUN_23e118c50,DAT_23eea9540,DAT_23eea9548,DAT_23eeab108,0,uVar6,
                               DAT_23eeab180,_DAT_23eea9538,&plStack_68,1);
        *(undefined4 *)(plVar8 + 5) = 0xa2;
        plStack_a0 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plStack_a0 == (longlong *)0x0) goto LAB_23e1181b0;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea94f8);
        if (plVar9 == (longlong *)0x0) goto LAB_23e118380;
        lVar7 = FUN_23e900ab0();
        if (lVar7 == 0) {
          FUN_23e915740(param_1,&plStack_68,DAT_23eea9500);
          plStack_98 = plStack_68;
          uStack_90 = uStack_60;
          plVar10 = plStack_58;
LAB_23e118247:
          *plVar9 = *plVar9 + -1;
          uVar15 = 0x120;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
            uVar15 = 0x120;
          }
        }
        else {
          plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea9508);
          if (plVar10 == (longlong *)0x0) {
LAB_23e118220:
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e118247;
          }
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea9510);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 == (longlong *)0x0) goto LAB_23e118220;
          *(undefined4 *)(plVar8 + 5) = 0x120;
          plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar11,_DAT_23eea9550);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar10 == (longlong *)0x0) goto LAB_23e118220;
          *(undefined4 *)(plVar8 + 5) = 0x120;
          plVar11 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          uVar4 = DAT_23eea9520;
          if (plVar11 == (longlong *)0x0) {
LAB_23e118380:
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uVar15 = 0x120;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            lVar7 = FUN_23e900960();
            if (lVar7 != 0) {
              uVar6 = _PyDict_NewPresized(2);
              PyDict_SetItem(uVar6,uVar4,lVar7);
              PyDict_SetItem(uVar6,_DAT_23eea9530,pcVar5);
              uVar4 = DAT_23eeab110;
              *plVar13 = *plVar13 + 1;
              plStack_68 = plVar13;
              plVar10 = (longlong *)
                        FUN_23e93e1e0(FUN_23e118f20,DAT_23eea9560,DAT_23eea9568,uVar4,0,uVar6,
                                      DAT_23eeab180,_DAT_23eea9558,&plStack_68,1);
              *(undefined4 *)(plVar8 + 5) = 0x120;
              plVar9 = (longlong *)FUN_23e914090(param_1,plVar11,plVar10);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar9 != (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea94f8);
                if (plVar12 == (longlong *)0x0) {
LAB_23e1184b0:
                  plStack_98 = *(longlong **)(param_1 + 0x60);
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  uVar15 = 0x148;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uStack_90 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar11 = DAT_23ed6a4f8;
                }
                else {
                  lVar7 = FUN_23e900ab0();
                  if (lVar7 == 0) {
                    FUN_23e915740(param_1,&plStack_68,DAT_23eea9500);
                    plStack_98 = plStack_68;
                    uStack_90 = uStack_60;
                    plVar10 = plStack_58;
                  }
                  else {
                    plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea9508);
                    if (plVar10 != (longlong *)0x0) {
                      plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea9510);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (plVar11 != (longlong *)0x0) {
                        *(undefined4 *)(plVar8 + 5) = 0x148;
                        plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar11,_DAT_23eea9570);
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar10 != (longlong *)0x0) {
                          *(undefined4 *)(plVar8 + 5) = 0x148;
                          plVar11 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          uVar4 = DAT_23eea9520;
                          if (plVar11 != (longlong *)0x0) {
                            lVar7 = FUN_23e900960();
                            if (lVar7 == 0) {
                              FUN_23e915740(param_1,&plStack_68,DAT_23eea9528);
                              plStack_98 = plStack_68;
                              lVar7 = *plVar11;
                              *plVar11 = lVar7 + -1;
                              if (lVar7 + -1 == 0) {
                                (**(code **)(plVar11[1] + 0x30))(plVar11);
                              }
                              uVar15 = 0x149;
                              plVar10 = plStack_58;
                              plVar11 = DAT_23ed6a4f8;
                              uStack_90 = uStack_60;
                              goto joined_r0x00023e117fb7;
                            }
                            uVar6 = _PyDict_NewPresized(2);
                            PyDict_SetItem(uVar6,uVar4,lVar7);
                            PyDict_SetItem(uVar6,_DAT_23eea9530,pcVar5);
                            uVar4 = DAT_23eeab118;
                            *plVar13 = *plVar13 + 1;
                            plStack_68 = plVar13;
                            plVar10 = (longlong *)
                                      FUN_23e93e1e0(FUN_23e1191f0,DAT_23eea9580,DAT_23eea9588,uVar4,
                                                    0,uVar6,DAT_23eeab180,_DAT_23eea9578,&plStack_68
                                                    ,1);
                            *(undefined4 *)(plVar8 + 5) = 0x148;
                            plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar10);
                            lVar7 = *plVar11;
                            *plVar11 = lVar7 + -1;
                            if (lVar7 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            if (plVar12 != (longlong *)0x0) {
                              lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                              plVar8 = *(longlong **)(lVar7 + 0x28);
                              plVar10 = (longlong *)plVar8[2];
                              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                   *(undefined8 *)(lVar7 + 0x30);
                              *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                              if (plVar10 != (longlong *)0x0) {
                                plVar8[2] = 0;
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))();
                                }
                              }
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              plVar8[0xf] = 0;
                              *(longlong *)pcVar5 = *(longlong *)pcVar5 + 1;
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                (**(code **)(plVar14[1] + 0x30))(plVar14);
                              }
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              lVar7 = *plStack_a0;
                              *plStack_a0 = lVar7 + -1;
                              if (lVar7 + -1 == 0) {
                                (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              *plVar1 = *plVar1 + -1;
                              if (*plVar1 != 0) {
                                return pcVar5;
                              }
                              (**(code **)(plVar1[1] + 0x30))(plVar1);
                              return pcVar5;
                            }
                          }
                          goto LAB_23e1184b0;
                        }
                      }
                    }
                    plStack_98 = *(longlong **)(param_1 + 0x60);
                    plVar10 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_90 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  *plVar12 = *plVar12 + -1;
                  uVar15 = 0x148;
                  plVar11 = DAT_23ed6a4f8;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                    uVar15 = 0x148;
                    plVar11 = DAT_23ed6a4f8;
                  }
                }
                goto joined_r0x00023e117fb7;
              }
              goto LAB_23e118380;
            }
            FUN_23e915740(param_1,&plStack_68,DAT_23eea9528);
            plStack_98 = plStack_68;
            *plVar11 = *plVar11 + -1;
            uStack_90 = uStack_60;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            uVar15 = 0x121;
            plVar10 = plStack_58;
          }
        }
        plVar9 = (longlong *)0x0;
        plVar11 = DAT_23ed6a4f8;
        goto joined_r0x00023e117fb7;
      }
      FUN_23e915740(param_1,&plStack_68,DAT_23eea9528);
      plStack_98 = plStack_68;
      *plVar11 = *plVar11 + -1;
      uStack_90 = uStack_60;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      uVar15 = 0xa3;
      plVar10 = plStack_58;
    }
  }
  plStack_a0 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e117fb7:
  DAT_23ed6a4f8 = plVar11;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = plVar11;
    }
    pcVar5 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar7 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar15;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar2 = plVar12[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar12 + -2;
    plVar12[-2] = lVar7;
    plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar12 + -2;
  }
  else {
    plVar12 = plVar10;
    if ((longlong *)plVar10[3] != plVar8) {
      if (plVar11 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar12 = plVar11;
      }
      pcVar5 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar8;
      *plVar8 = *plVar8 + 1;
      lVar7 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar15;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar2 = plVar12[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar12 + -2;
      plVar12[-2] = lVar7;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar10;
      if (lVar2 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar8,"occooo",plVar1,plVar14,plVar13,plStack_a0,plVar9,0);
  if (_DAT_23eeab128 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eeab128 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar10 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar7 = *plStack_a0, *plStack_a0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_98,uStack_90,plVar12);
  return (code *)0x0;
}
