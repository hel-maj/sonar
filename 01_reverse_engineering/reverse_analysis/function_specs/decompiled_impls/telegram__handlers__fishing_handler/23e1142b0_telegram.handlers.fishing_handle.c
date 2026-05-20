/* ===== 23e1142b0 telegram.handlers.fishing_handle:24 ===== */
/* ghidra_name=forced_23e1142b0 entry=23e1142b0 size=6929 */

longlong forced_23e1142b0(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  code *pcVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  undefined4 uVar16;
  longlong *plVar17;
  longlong *plStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  longlong *plStack_80;
  undefined8 uStack_78;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = DAT_23eeab188;
  if (DAT_23eeab188 == (longlong *)0x0) {
LAB_23e1142ea:
    DAT_23eeab188 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab178,DAT_23eeab180,0x48);
  }
  else {
    lVar7 = *DAT_23eeab188;
    if (1 < lVar7) {
      *DAT_23eeab188 = lVar7 + -1;
      goto LAB_23e1142ea;
    }
    if (DAT_23eeab188[2] != 0) {
      *DAT_23eeab188 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e1142ea;
    }
  }
  plVar2 = DAT_23eeab188;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar10 = DAT_23eeab188 + 9;
  lVar1 = *(longlong *)(lVar7 + 8);
  DAT_23eeab188[0xf] = lVar1;
  *(longlong **)(lVar7 + 8) = plVar10;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar2[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar7 = FUN_23e9013c0();
  if (lVar7 == 0) {
    FUN_23e915740(param_1,&plStack_68,DAT_23eea9210);
    plStack_80 = plStack_68;
    uStack_78 = uStack_60;
    plVar8 = (longlong *)0x0;
    plVar10 = plStack_58;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0x1a;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,lVar7,DAT_23eea9218);
    if (plVar8 != (longlong *)0x0) {
      pcVar9 = (code *)FUN_23e901290();
      if (pcVar9 == (code *)0x0) {
LAB_23e1154b8:
        pcVar15 = (code *)0x0;
        FUN_23e915740(param_1,&plStack_68,DAT_23eea9200);
        plStack_80 = plStack_68;
        uStack_78 = uStack_60;
        plVar10 = plStack_58;
      }
      else {
        pcVar15 = _Py_TrueStruct_exref;
        if (pcVar9 == _Py_NoneStruct_exref) {
          pcVar15 = _Py_FalseStruct_exref;
        }
        iVar6 = FUN_23a35f020(pcVar15);
        if (iVar6 != 1) {
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
LAB_23e1143df:
          iVar6 = FUN_23a35f020(pcVar15);
          if (iVar6 == -1) {
            plStack_80 = *(longlong **)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar12 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            uVar16 = 0x1e;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            plStack_90 = (longlong *)0x0;
            plStack_98 = (longlong *)0x0;
            plStack_a0 = (longlong *)0x0;
            plStack_88 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plStack_88 = DAT_23eea9230;
            if (iVar6 != 0) {
              plStack_88 = DAT_23eea9228;
            }
            *plStack_88 = *plStack_88 + 1;
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
            if (plVar10 == (longlong *)0x0) {
              plStack_80 = *(longlong **)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              plVar13 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar12 = (longlong *)0x0;
              uVar16 = 0x21;
              uStack_78 = *(undefined8 *)(param_1 + 0x68);
              plStack_90 = (longlong *)0x0;
              plStack_98 = (longlong *)0x0;
              plStack_a0 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar2 + 5) = 0x21;
              plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23eea9238);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 == (longlong *)0x0) {
                plStack_80 = *(longlong **)(param_1 + 0x60);
                plVar10 = *(longlong **)(param_1 + 0x70);
                plVar13 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar11 = (longlong *)0x0;
                uVar16 = 0x21;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                plStack_90 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                plStack_a0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar12 = (longlong *)0x0;
              }
              else {
                iVar6 = FUN_23a35f020(plVar11);
                lVar7 = *plVar11 + -1;
                if (iVar6 == -1) {
                  plStack_80 = *(longlong **)(param_1 + 0x60);
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = lVar7;
                  if (lVar7 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  uVar16 = 0x21;
                  plVar13 = (longlong *)0x0;
                  plVar12 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_90 = (longlong *)0x0;
                  plStack_98 = (longlong *)0x0;
                  plStack_a0 = (longlong *)0x0;
                }
                else {
                  *plVar11 = lVar7;
                  if (lVar7 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  uVar4 = DAT_23ed6ce40;
                  plVar11 = DAT_23eea9248;
                  if (iVar6 != 0) {
                    plVar11 = DAT_23eea9240;
                  }
                  *plVar11 = *plVar11 + 1;
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,uVar4);
                  if (plVar10 == (longlong *)0x0) {
                    plStack_80 = *(longlong **)(param_1 + 0x60);
                    plVar10 = *(longlong **)(param_1 + 0x70);
                    plVar13 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar16 = 0x22;
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plStack_90 = (longlong *)0x0;
                    plStack_98 = (longlong *)0x0;
                    plStack_a0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar12 = (longlong *)0x0;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0x22;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23eea9250);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar12 == (longlong *)0x0) {
                      plStack_80 = *(longlong **)(param_1 + 0x60);
                      plVar10 = *(longlong **)(param_1 + 0x70);
                      plVar12 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar16 = 0x22;
                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                      plStack_90 = (longlong *)0x0;
                      plStack_98 = (longlong *)0x0;
                      plStack_a0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar13 = (longlong *)0x0;
                    }
                    else {
                      iVar6 = FUN_23a35f020(plVar12);
                      lVar7 = *plVar12 + -1;
                      if (iVar6 == -1) {
                        plStack_80 = *(longlong **)(param_1 + 0x60);
                        plVar10 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar12 = lVar7;
                        if (lVar7 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        plStack_90 = (longlong *)0x0;
                        uVar16 = 0x22;
                        plVar13 = (longlong *)0x0;
                        plVar12 = (longlong *)0x0;
                        plStack_98 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
                      }
                      else {
                        *plVar12 = lVar7;
                        if (lVar7 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        uVar4 = DAT_23ed6ce40;
                        plVar12 = DAT_23eea9260;
                        if (iVar6 != 0) {
                          plVar12 = DAT_23eea9258;
                        }
                        *plVar12 = *plVar12 + 1;
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,uVar4);
                        if (plVar10 == (longlong *)0x0) {
                          plStack_80 = *(longlong **)(param_1 + 0x60);
                          plVar10 = *(longlong **)(param_1 + 0x70);
                          plStack_90 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar16 = 0x23;
                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                          plStack_98 = (longlong *)0x0;
                          plStack_a0 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar13 = (longlong *)0x0;
                        }
                        else {
                          *(undefined4 *)(plVar2 + 5) = 0x23;
                          plVar13 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23eea9268);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar13 == (longlong *)0x0) {
                            plStack_80 = *(longlong **)(param_1 + 0x60);
                            plVar10 = *(longlong **)(param_1 + 0x70);
                            plVar13 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar16 = 0x23;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_90 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_a0 = (longlong *)0x0;
                          }
                          else {
                            iVar6 = FUN_23a35f020(plVar13);
                            lVar7 = *plVar13 + -1;
                            if (iVar6 == -1) {
                              plStack_80 = *(longlong **)(param_1 + 0x60);
                              plVar10 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar13 = lVar7;
                              if (lVar7 == 0) {
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              plStack_90 = (longlong *)0x0;
                              uVar16 = 0x23;
                              plVar13 = (longlong *)0x0;
                              plStack_98 = (longlong *)0x0;
                              plStack_a0 = (longlong *)0x0;
                            }
                            else {
                              *plVar13 = lVar7;
                              if (lVar7 == 0) {
                                (**(code **)(plVar13[1] + 0x30))();
                              }
                              uVar4 = DAT_23ed6ce40;
                              plVar13 = DAT_23eea9278;
                              if (iVar6 != 0) {
                                plVar13 = DAT_23eea9270;
                              }
                              *plVar13 = *plVar13 + 1;
                              plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,uVar4);
                              if (plVar10 == (longlong *)0x0) {
                                plStack_80 = *(longlong **)(param_1 + 0x60);
                                plVar10 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar16 = 0x24;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                plStack_98 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_a0 = (longlong *)0x0;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0x24;
                                plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23eea9280);
                                lVar7 = *plVar10;
                                *plVar10 = lVar7 + -1;
                                if (lVar7 + -1 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))();
                                }
                                if (plVar14 == (longlong *)0x0) {
                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                  plStack_90 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar16 = 0x24;
                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                  plStack_a0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plStack_98 = (longlong *)0x0;
                                }
                                else {
                                  iVar6 = FUN_23a35f020(plVar14);
                                  lVar7 = *plVar14 + -1;
                                  if (iVar6 == -1) {
                                    plStack_80 = *(longlong **)(param_1 + 0x60);
                                    plVar10 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar14 = lVar7;
                                    if (lVar7 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                    }
                                    plStack_90 = (longlong *)0x0;
                                    uVar16 = 0x24;
                                    plStack_98 = (longlong *)0x0;
                                    plStack_a0 = (longlong *)0x0;
                                  }
                                  else {
                                    *plVar14 = lVar7;
                                    if (lVar7 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))();
                                    }
                                    uVar4 = DAT_23ed6ce40;
                                    plStack_a0 = DAT_23eea9290;
                                    if (iVar6 != 0) {
                                      plStack_a0 = DAT_23eea9288;
                                    }
                                    *plStack_a0 = *plStack_a0 + 1;
                                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,uVar4);
                                    if (plVar10 == (longlong *)0x0) {
                                      plStack_80 = *(longlong **)(param_1 + 0x60);
                                      plVar10 = *(longlong **)(param_1 + 0x70);
                                      plStack_90 = (longlong *)0x0;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar16 = 0x25;
                                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plStack_98 = (longlong *)0x0;
                                    }
                                    else {
                                      *(undefined4 *)(plVar2 + 5) = 0x25;
                                      plVar14 = (longlong *)
                                                FUN_23e94bb80(param_1,plVar10,DAT_23eea9298);
                                      lVar7 = *plVar10;
                                      *plVar10 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                      }
                                      if (plVar14 == (longlong *)0x0) {
                                        plStack_80 = *(longlong **)(param_1 + 0x60);
                                        plVar10 = *(longlong **)(param_1 + 0x70);
                                        plStack_98 = (longlong *)0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar16 = 0x25;
                                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_90 = (longlong *)0x0;
                                      }
                                      else {
                                        iVar6 = FUN_23a35f020(plVar14);
                                        lVar7 = *plVar14 + -1;
                                        if (iVar6 == -1) {
                                          plStack_80 = *(longlong **)(param_1 + 0x60);
                                          plVar10 = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar14 = lVar7;
                                          if (lVar7 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))();
                                          }
                                          plStack_90 = (longlong *)0x0;
                                          uVar16 = 0x25;
                                          plStack_98 = (longlong *)0x0;
                                        }
                                        else {
                                          *plVar14 = lVar7;
                                          if (lVar7 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))();
                                          }
                                          plStack_98 = DAT_23eea92a8;
                                          if (iVar6 != 0) {
                                            plStack_98 = DAT_23eea92a0;
                                          }
                                          *plStack_98 = *plStack_98 + 1;
                                          lVar7 = FUN_23e901140();
                                          if (lVar7 == 0) {
                                            FUN_23e915740(param_1,&plStack_68,DAT_23eea92b0);
                                            uVar16 = 0x27;
                                            plStack_80 = plStack_68;
                                            uStack_78 = uStack_60;
                                            plStack_90 = (longlong *)0x0;
                                            plVar10 = plStack_58;
                                          }
                                          else {
                                            *(undefined4 *)(plVar2 + 5) = 0x27;
                                            plStack_90 = (longlong *)FUN_23e91a870(param_1,lVar7);
                                            if (plStack_90 == (longlong *)0x0) {
                                              plStack_80 = *(longlong **)(param_1 + 0x60);
                                              plVar10 = *(longlong **)(param_1 + 0x70);
                                              uVar16 = 0x27;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              plVar10 = (longlong *)
                                                        FUN_23e8bc2f0(plStack_90,DAT_23eea92b8);
                                              uVar5 = DAT_23eea92c8;
                                              uVar4 = DAT_23eea92c0;
                                              if (plVar10 != (longlong *)0x0) {
                                                *(undefined4 *)(plVar2 + 5) = 0x28;
                                                uStack_60 = uVar4;
                                                plStack_68 = plStack_88;
                                                plVar14 = (longlong *)
                                                          FUN_23e9186b0(param_1,plVar10,&plStack_68,
                                                                        uVar5);
                                                *plVar10 = *plVar10 + -1;
                                                if (*plVar10 == 0) {
                                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                }
                                                if (plVar14 != (longlong *)0x0) {
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                  }
                                                  plVar10 = (longlong *)
                                                            FUN_23e8bc2f0(plStack_90,DAT_23eea92b8);
                                                  uVar5 = DAT_23eea92d0;
                                                  uVar4 = DAT_23eea92c8;
                                                  if (plVar10 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar2 + 5) = 0x29;
                                                    uStack_60 = uVar5;
                                                    plStack_68 = plVar11;
                                                    plVar14 = (longlong *)
                                                              FUN_23e9186b0(param_1,plVar10,
                                                                            &plStack_68,uVar4);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                    }
                                                    if (plVar14 != (longlong *)0x0) {
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                      }
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(plStack_90,
                                                                              DAT_23eea92b8);
                                                      uVar5 = DAT_23eea92d8;
                                                      uVar4 = DAT_23eea92c8;
                                                      if (plVar10 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar2 + 5) = 0x2a;
                                                        uStack_60 = uVar5;
                                                        plStack_68 = plVar12;
                                                        plVar14 = (longlong *)
                                                                  FUN_23e9186b0(param_1,plVar10,
                                                                                &plStack_68,uVar4);
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                        }
                                                        if (plVar14 != (longlong *)0x0) {
                                                          *plVar14 = *plVar14 + -1;
                                                          if (*plVar14 == 0) {
                                                            (**(code **)(plVar14[1] + 0x30))
                                                                      (plVar14);
                                                          }
                                                          plVar10 = (longlong *)
                                                                    FUN_23e8bc2f0(plStack_90,
                                                                                  DAT_23eea92b8);
                                                          uVar5 = DAT_23eea92e0;
                                                          uVar4 = DAT_23eea92c8;
                                                          if (plVar10 != (longlong *)0x0) {
                                                            *(undefined4 *)(plVar2 + 5) = 0x2b;
                                                            uStack_60 = uVar5;
                                                            plStack_68 = plVar13;
                                                            plVar14 = (longlong *)
                                                                      FUN_23e9186b0(param_1,plVar10,
                                                                                    &plStack_68,
                                                                                    uVar4);
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              (**(code **)(plVar10[1] + 0x30))
                                                                        (plVar10);
                                                            }
                                                            if (plVar14 != (longlong *)0x0) {
                                                              *plVar14 = *plVar14 + -1;
                                                              if (*plVar14 == 0) {
                                                                (**(code **)(plVar14[1] + 0x30))
                                                                          (plVar14);
                                                              }
                                                              plVar10 = (longlong *)
                                                                        FUN_23e8bc2f0(plStack_90,
                                                                                      DAT_23eea92b8)
                                                              ;
                                                              uVar5 = DAT_23eea92e8;
                                                              uVar4 = DAT_23eea92c8;
                                                              if (plVar10 != (longlong *)0x0) {
                                                                *(undefined4 *)(plVar2 + 5) = 0x2c;
                                                                uStack_60 = uVar5;
                                                                plStack_68 = plStack_a0;
                                                                plVar14 = (longlong *)
                                                                          FUN_23e9186b0(param_1,
                                                  plVar10,&plStack_68,uVar4);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                  }
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                    }
                                                    plVar10 = (longlong *)
                                                              FUN_23e8bc2f0(plStack_90,DAT_23eea92b8
                                                                           );
                                                    uVar5 = DAT_23eea92f0;
                                                    uVar4 = DAT_23eea92c8;
                                                    if (plVar10 != (longlong *)0x0) {
                                                      *(undefined4 *)(plVar2 + 5) = 0x2d;
                                                      uStack_60 = uVar5;
                                                      plStack_68 = plStack_98;
                                                      plVar14 = (longlong *)
                                                                FUN_23e9186b0(param_1,plVar10,
                                                                              &plStack_68,uVar4);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                      }
                                                      if (plVar14 != (longlong *)0x0) {
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                        }
                                                        plVar10 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_90,
                                                                                DAT_23eea92b8);
                                                        lVar7 = DAT_23eea92f8;
                                                        if (plVar10 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar2 + 5) = 0x2e;
                                                          plVar14 = (longlong *)
                                                                    FUN_23e9186b0(param_1,plVar10,
                                                                                  lVar7 + 0x18,
                                                                                  DAT_23eea92c8);
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            (**(code **)(plVar10[1] + 0x30))
                                                                      (plVar10);
                                                          }
                                                          if (plVar14 != (longlong *)0x0) {
                                                            *plVar14 = *plVar14 + -1;
                                                            if (*plVar14 == 0) {
                                                              (**(code **)(plVar14[1] + 0x30))
                                                                        (plVar14);
                                                            }
                                                            plVar10 = (longlong *)
                                                                      FUN_23e8bc2f0(plStack_90,
                                                                                    DAT_23eea92b8);
                                                            lVar7 = DAT_23eea9300;
                                                            if (plVar10 != (longlong *)0x0) {
                                                              *(undefined4 *)(plVar2 + 5) = 0x2f;
                                                              plVar14 = (longlong *)
                                                                        FUN_23e9186b0(param_1,
                                                  plVar10,lVar7 + 0x18,DAT_23eea92c8);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                  }
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                    }
                                                    plVar10 = (longlong *)
                                                              FUN_23e8bc2f0(plStack_90,DAT_23eea92b8
                                                                           );
                                                    lVar7 = DAT_23eea9308;
                                                    if (plVar10 != (longlong *)0x0) {
                                                      *(undefined4 *)(plVar2 + 5) = 0x30;
                                                      plVar14 = (longlong *)
                                                                FUN_23e9186b0(param_1,plVar10,
                                                                              lVar7 + 0x18,
                                                                              DAT_23eea92c8);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                      }
                                                      if (plVar14 != (longlong *)0x0) {
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                        }
                                                        plVar10 = (longlong *)
                                                                  FUN_23e8bc2f0(plStack_90,
                                                                                DAT_23eea92b8);
                                                        lVar7 = DAT_23eea9310;
                                                        if (plVar10 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar2 + 5) = 0x31;
                                                          plVar14 = (longlong *)
                                                                    FUN_23e9186b0(param_1,plVar10,
                                                                                  lVar7 + 0x18,
                                                                                  DAT_23eea92c8);
                                                          *plVar10 = *plVar10 + -1;
                                                          if (*plVar10 == 0) {
                                                            (**(code **)(plVar10[1] + 0x30))
                                                                      (plVar10);
                                                          }
                                                          if (plVar14 != (longlong *)0x0) {
                                                            *plVar14 = *plVar14 + -1;
                                                            if (*plVar14 == 0) {
                                                              (**(code **)(plVar14[1] + 0x30))
                                                                        (plVar14);
                                                            }
                                                            plVar10 = (longlong *)
                                                                      FUN_23e8bc2f0(plStack_90,
                                                                                    DAT_23eea92b8);
                                                            lVar7 = DAT_23eea9318;
                                                            if (plVar10 != (longlong *)0x0) {
                                                              *(undefined4 *)(plVar2 + 5) = 0x32;
                                                              plVar14 = (longlong *)
                                                                        FUN_23e9186b0(param_1,
                                                  plVar10,lVar7 + 0x18,DAT_23eea92c8);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    (**(code **)(plVar10[1] + 0x30))();
                                                  }
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                                    }
                                                    lVar7 = DAT_23eea9328;
                                                    *(undefined4 *)(plVar2 + 5) = 0x33;
                                                    plVar10 = (longlong *)
                                                              FUN_23e915840(param_1,plStack_90,
                                                                            DAT_23eea9320,
                                                                            *(undefined8 *)
                                                                             (lVar7 + 0x18));
                                                    if (plVar10 == (longlong *)0x0) {
                                                      plStack_80 = *(longlong **)(param_1 + 0x60);
                                                      plVar10 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar16 = 0x33;
                                                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                      }
                                                      *(undefined4 *)(plVar2 + 5) = 0x34;
                                                      lVar7 = FUN_23e91bfe0(param_1,plStack_90,
                                                                            DAT_23eea9330);
                                                      if (lVar7 != 0) {
                                                        lVar1 = *(longlong *)
                                                                 (*(longlong *)(param_1 + 0x38) + 8)
                                                        ;
                                                        plVar10 = *(longlong **)(lVar1 + 0x28);
                                                        *(undefined8 *)
                                                         (*(longlong *)(param_1 + 0x38) + 8) =
                                                             *(undefined8 *)(lVar1 + 0x30);
                                                        plVar2 = (longlong *)plVar10[2];
                                                        *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                                                        if (plVar2 != (longlong *)0x0) {
                                                          plVar10[2] = 0;
                                                          *plVar2 = *plVar2 + -1;
                                                          if (*plVar2 == 0) {
                                                            (**(code **)(plVar2[1] + 0x30))();
                                                          }
                                                        }
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                                                        }
                                                        plVar10[0xf] = 0;
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                                                        }
                                                        *(longlong *)pcVar15 =
                                                             *(longlong *)pcVar15 + -1;
                                                        if (*(longlong *)pcVar15 == 0) {
                                                          (**(code **)(*(longlong *)(pcVar15 + 8) +
                                                                      0x30))(pcVar15);
                                                        }
                                                        lVar1 = *plStack_88;
                                                        *plStack_88 = lVar1 + -1;
                                                        if (lVar1 + -1 == 0) {
                                                          (**(code **)(plStack_88[1] + 0x30))
                                                                    (plStack_88);
                                                        }
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) {
                                                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                                                        }
                                                        *plVar12 = *plVar12 + -1;
                                                        if (*plVar12 == 0) {
                                                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                                                        }
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                                                        }
                                                        lVar1 = *plStack_a0;
                                                        *plStack_a0 = lVar1 + -1;
                                                        if (lVar1 + -1 == 0) {
                                                          (**(code **)(plStack_a0[1] + 0x30))
                                                                    (plStack_a0);
                                                        }
                                                        lVar1 = *plStack_98;
                                                        *plStack_98 = lVar1 + -1;
                                                        if (lVar1 + -1 == 0) {
                                                          (**(code **)(plStack_98[1] + 0x30))
                                                                    (plStack_98);
                                                        }
                                                        lVar1 = *plStack_90;
                                                        *plStack_90 = lVar1 + -1;
                                                        if (lVar1 + -1 != 0) {
                                                          return lVar7;
                                                        }
                                                        (**(code **)(plStack_90[1] + 0x30))
                                                                  (plStack_90);
                                                        return lVar7;
                                                      }
                                                      plStack_80 = *(longlong **)(param_1 + 0x60);
                                                      plVar10 = *(longlong **)(param_1 + 0x70);
                                                      uVar16 = 0x34;
                                                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                    }
                                                    goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x32;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x31;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x30;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2f;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2e;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2d;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2c;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2b;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x2a;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                  }
                                                  }
                                                  plStack_80 = *(longlong **)(param_1 + 0x60);
                                                  plVar10 = *(longlong **)(param_1 + 0x70);
                                                  uVar16 = 0x29;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e115050;
                                                }
                                              }
                                              plStack_80 = *(longlong **)(param_1 + 0x60);
                                              plVar10 = *(longlong **)(param_1 + 0x70);
                                              uVar16 = 0x28;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
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
          goto LAB_23e115050;
        }
        lVar7 = FUN_23e901290();
        if (lVar7 == 0) goto LAB_23e1154b8;
        pcVar15 = (code *)FUN_23e8bc2f0(lVar7,DAT_23eea9220);
        if (pcVar15 != (code *)0x0) goto LAB_23e1143df;
        plStack_80 = *(longlong **)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_78 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plStack_90 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_98 = (longlong *)0x0;
      uVar16 = 0x1d;
      plStack_a0 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      goto LAB_23e115050;
    }
    plStack_80 = *(longlong **)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  plStack_90 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  pcVar15 = (code *)0x0;
  plVar12 = (longlong *)0x0;
  plStack_98 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  uVar16 = 0x1a;
  plStack_a0 = (longlong *)0x0;
  plStack_88 = (longlong *)0x0;
LAB_23e115050:
  plVar14 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar7 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar16;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar1 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar7;
    plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar14 + -2;
    plVar17 = plVar14;
  }
  else {
    plVar17 = plVar10;
    if ((longlong *)plVar10[3] != plVar2) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar17 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar2;
      *plVar2 = *plVar2 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar16;
      pcVar9 = _PyRuntime_exref;
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar14[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar14 + -2;
      plVar14[-2] = lVar7;
      plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar10;
      plVar17 = plVar14;
      if (lVar1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar2,"ooooooooo",plVar8,pcVar15,plStack_88,plVar11,plVar12,plVar13,plStack_a0,
                plStack_98,plStack_90);
  if (DAT_23eeab188 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23eeab188 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar7 + 0x28);
  plVar2 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  if ((plStack_88 != (longlong *)0x0) &&
     (lVar7 = *plStack_88, *plStack_88 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_88[1] + 0x30))(plStack_88);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar7 = *plStack_a0, *plStack_a0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plStack_98 != (longlong *)0x0) &&
     (lVar7 = *plStack_98, *plStack_98 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
  }
  if ((plStack_90 != (longlong *)0x0) &&
     (lVar7 = *plStack_90, *plStack_90 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_90[1] + 0x30))(plStack_90);
  }
  FUN_23a33aa70(param_1,plStack_80,uStack_78,plVar17);
  return 0;
}
