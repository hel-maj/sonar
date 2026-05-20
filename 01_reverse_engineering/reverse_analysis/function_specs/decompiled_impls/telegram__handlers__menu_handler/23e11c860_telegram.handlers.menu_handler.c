/* ===== 23e11c860 telegram.handlers.menu_handler:44 ===== */
/* ghidra_name=FUN_23e11c860 entry=23e11c860 size=5601 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e11c860(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined4 uVar17;
  longlong lVar18;
  undefined8 uStack_a0;
  longlong *plStack_98;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar16 = DAT_23ed6a4e0;
  plVar1 = (longlong *)*param_3;
  lVar11 = param_3[1];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar16 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar5 = _PyRuntime_exref;
  plVar16[2] = lVar11;
  plVar7 = _DAT_23eeab060;
  lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar16[-1];
  puVar3 = *(undefined8 **)(lVar11 + 8);
  *puVar3 = plVar16 + -2;
  plVar16[-2] = lVar11;
  plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar11 + 8) = plVar16 + -2;
  if (plVar7 == (longlong *)0x0) {
LAB_23e11c913:
    plVar7 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeab058,DAT_23eeab0a8,0x30);
    _DAT_23eeab060 = plVar7;
  }
  else {
    lVar11 = *plVar7;
    if (1 < lVar11) {
      *plVar7 = lVar11 + -1;
      goto LAB_23e11c913;
    }
    if (plVar7[2] != 0) {
      *plVar7 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e11c913;
    }
  }
  lVar11 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(lVar11 + 8);
  plVar7[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar7 + 9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar4 = _DAT_23eea8f00;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar4);
  if (plVar8 == (longlong *)0x0) goto LAB_23e11d490;
  lVar11 = *(longlong *)(_DAT_23eea8e58 + 0x20);
  if (*(char *)(lVar11 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(_DAT_23eea8e58,_DAT_23eea8f08);
    if (plVar9 == (longlong *)0x0) goto LAB_23e11d3d9;
    lVar11 = *plVar9;
LAB_23e11d868:
    if (lVar11 == 0) goto LAB_23e11d3d9;
LAB_23e11ca1e:
    *(undefined4 *)(plVar7 + 5) = 0x2f;
    plVar9 = (longlong *)FUN_23e91a870(param_1);
    if (plVar9 == (longlong *)0x0) {
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plStack_58 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_a0 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
    else {
      *(undefined4 *)(plVar7 + 5) = 0x2f;
      plVar10 = (longlong *)FUN_23e914090(param_1,plVar8,plVar9);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      uVar4 = _DAT_23eea8f00;
      if (plVar10 != (longlong *)0x0) {
        lVar11 = FUN_23e900440();
        if (lVar11 == 0) {
          FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f10);
          plStack_98 = plStack_68;
          *plVar10 = *plVar10 + -1;
          uStack_a0 = uStack_60;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          uVar17 = 0x30;
          goto LAB_23e11d4bb;
        }
        uVar12 = _PyDict_NewPresized(2);
        PyDict_SetItem(uVar12,uVar4,lVar11);
        pcVar5 = _Py_NoneStruct_exref;
        PyDict_SetItem(uVar12,_DAT_23eea8f18,_Py_NoneStruct_exref);
        uVar4 = _DAT_23eeab030;
        *plVar16 = *plVar16 + 1;
        plStack_68 = plVar16;
        plVar9 = (longlong *)
                 FUN_23e93e1e0(FUN_23e11ded0,_DAT_23eea8f28,_DAT_23eea8f30,uVar4,0,uVar12,
                               DAT_23eeab0a8,_DAT_23eea8f20,&plStack_68,1);
        *(undefined4 *)(plVar7 + 5) = 0x2f;
        plVar8 = (longlong *)FUN_23e914090(param_1,plVar10,plVar9);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar8 == (longlong *)0x0) goto LAB_23e11d490;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea8f00);
        if (plVar9 == (longlong *)0x0) {
LAB_23e11d6d0:
          plStack_98 = *(longlong **)(param_1 + 0x60);
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar17 = 0x44;
          uStack_a0 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e11d6fb;
        }
        lVar11 = FUN_23e9002f0();
        if (lVar11 == 0) {
          FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f38);
          plStack_98 = plStack_68;
          uStack_a0 = uStack_60;
          plVar10 = plStack_58;
LAB_23e11d826:
          *plVar9 = *plVar9 + -1;
          uVar17 = 0x44;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
            uVar17 = 0x44;
          }
        }
        else {
          plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eea8f40);
          if (plVar10 == (longlong *)0x0) {
LAB_23e11d800:
            plStack_98 = *(longlong **)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_a0 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e11d826;
          }
          plVar13 = (longlong *)FUN_23e8cb9c0(plVar10,_DAT_23eea8f48);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar13 == (longlong *)0x0) goto LAB_23e11d800;
          *(undefined4 *)(plVar7 + 5) = 0x44;
          plVar14 = (longlong *)FUN_23e914090(param_1,plVar9,plVar13);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar14 == (longlong *)0x0) goto LAB_23e11d6d0;
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea8f00);
          if (plVar9 == (longlong *)0x0) {
LAB_23e11da60:
            plStack_98 = *(longlong **)(param_1 + 0x60);
            uVar17 = 0x45;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_a0 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            lVar11 = *plVar14;
            *plVar14 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar14[1] + 0x30))();
              uVar17 = 0x45;
            }
            goto LAB_23e11d6fb;
          }
          lVar11 = *(longlong *)(_DAT_23eea8e58 + 0x20);
          if (*(char *)(lVar11 + 10) == '\0') {
            plVar10 = (longlong *)FUN_23a37a020(_DAT_23eea8e58,_DAT_23eea8f50);
            if (plVar10 == (longlong *)0x0) goto LAB_23e11d8f0;
            lVar18 = *plVar10;
LAB_23e11d8dc:
            if (lVar18 == 0) goto LAB_23e11d8f0;
LAB_23e11ccce:
            *(undefined4 *)(plVar7 + 5) = 0x45;
            plVar10 = (longlong *)FUN_23e94bb80(param_1,lVar18,_DAT_23eea8f58);
            if (plVar10 == (longlong *)0x0) {
              plStack_98 = *(longlong **)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_a0 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e11d94d;
            }
            *(undefined4 *)(plVar7 + 5) = 0x45;
            plVar13 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            uVar4 = _DAT_23eea8f00;
            if (plVar13 == (longlong *)0x0) goto LAB_23e11da60;
            lVar11 = FUN_23e900440();
            if (lVar11 == 0) {
              FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f10);
              plStack_98 = plStack_68;
              uStack_a0 = uStack_60;
              lVar11 = *plVar14;
              *plVar14 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              uVar17 = 0x46;
              plVar10 = plStack_58;
            }
            else {
              uVar12 = _PyDict_NewPresized(2);
              PyDict_SetItem(uVar12,uVar4,lVar11);
              PyDict_SetItem(uVar12,_DAT_23eea8f18,pcVar5);
              uVar4 = _DAT_23eeab040;
              *plVar16 = *plVar16 + 1;
              plStack_68 = plVar16;
              plVar9 = (longlong *)
                       FUN_23e93e1e0(FUN_23e11e190,_DAT_23eea8f68,_DAT_23eea8f70,uVar4,0,uVar12,
                                     DAT_23eeab0a8,_DAT_23eea8f60,&plStack_68,1);
              *(undefined4 *)(plVar7 + 5) = 0x45;
              plVar10 = (longlong *)FUN_23e914090(param_1,plVar13,plVar9);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar10 != (longlong *)0x0) {
                *(undefined4 *)(plVar7 + 5) = 0x44;
                plVar9 = (longlong *)FUN_23e914090(param_1,plVar14,plVar10);
                lVar11 = *plVar14;
                *plVar14 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar9 == (longlong *)0x0) goto LAB_23e11d6d0;
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea8f78);
                if (plVar13 == (longlong *)0x0) goto LAB_23e11db88;
                lVar11 = FUN_23e9002f0();
                if (lVar11 == 0) {
                  FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f38);
                  plStack_98 = plStack_68;
                  uStack_a0 = uStack_60;
                  plVar10 = plStack_58;
LAB_23e11da36:
                  *plVar13 = *plVar13 + -1;
                  uVar17 = 0x51;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                    uVar17 = 0x51;
                  }
                }
                else {
                  plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eea8f80);
                  if (plVar10 == (longlong *)0x0) {
LAB_23e11da10:
                    plStack_98 = *(longlong **)(param_1 + 0x60);
                    plVar10 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_a0 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e11da36;
                  }
                  plVar14 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea8f88);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  uVar4 = _DAT_23eea8f90;
                  if (plVar14 == (longlong *)0x0) goto LAB_23e11da10;
                  *(undefined4 *)(plVar7 + 5) = 0x51;
                  plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar14,uVar4);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar10 == (longlong *)0x0) goto LAB_23e11da10;
                  *(undefined4 *)(plVar7 + 5) = 0x51;
                  plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar10);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  uVar4 = _DAT_23eea8f98;
                  if (plVar14 == (longlong *)0x0) {
LAB_23e11db88:
                    plStack_98 = *(longlong **)(param_1 + 0x60);
                    plVar10 = *(longlong **)(param_1 + 0x70);
                    uVar17 = 0x51;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_a0 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    lVar11 = FUN_23e9001a0();
                    if (lVar11 != 0) {
                      uVar12 = _PyDict_NewPresized(2);
                      PyDict_SetItem(uVar12,uVar4,lVar11);
                      PyDict_SetItem(uVar12,_DAT_23eea8f18,pcVar5);
                      uVar4 = _DAT_23eeab048;
                      *plVar16 = *plVar16 + 1;
                      plStack_68 = plVar16;
                      plVar10 = (longlong *)
                                FUN_23e93e1e0(FUN_23e11e450,_DAT_23eea8fb0,_DAT_23eea8fb8,uVar4,0,
                                              uVar12,DAT_23eeab0a8,_DAT_23eea8fa8,&plStack_68,1);
                      *(undefined4 *)(plVar7 + 5) = 0x51;
                      plVar13 = (longlong *)FUN_23e914090(param_1,plVar14,plVar10);
                      lVar11 = *plVar14;
                      *plVar14 = lVar11 + -1;
                      if (lVar11 + -1 == 0) {
                        (**(code **)(plVar14[1] + 0x30))();
                      }
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (plVar13 != (longlong *)0x0) {
                        plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eea8f78);
                        if (plVar15 == (longlong *)0x0) {
LAB_23e11dcb0:
                          plStack_98 = *(longlong **)(param_1 + 0x60);
                          plVar10 = *(longlong **)(param_1 + 0x70);
                          uVar17 = 0x77;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uStack_a0 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar14 = DAT_23ed6a4f8;
                        }
                        else {
                          lVar11 = FUN_23e9002f0();
                          if (lVar11 == 0) {
                            FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f38);
                            plStack_98 = plStack_68;
                            uStack_a0 = uStack_60;
                            plVar10 = plStack_58;
                          }
                          else {
                            plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eea8f80);
                            if (plVar10 == (longlong *)0x0) {
                              plStack_98 = *(longlong **)(param_1 + 0x60);
                              uVar17 = 0x77;
                              plVar10 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_a0 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              lVar11 = *plVar15;
                              *plVar15 = lVar11 + -1;
                              plVar14 = DAT_23ed6a4f8;
                              if (lVar11 + -1 == 0) {
                                (**(code **)(plVar15[1] + 0x30))();
                                uVar17 = 0x77;
                                plVar14 = DAT_23ed6a4f8;
                              }
                              goto joined_r0x00023e11d704;
                            }
                            plVar14 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eea8f88);
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            if (plVar14 != (longlong *)0x0) {
                              *(undefined4 *)(plVar7 + 5) = 0x77;
                              plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar14,_DAT_23eea8fc0);
                              *plVar14 = *plVar14 + -1;
                              if (*plVar14 == 0) {
                                (**(code **)(plVar14[1] + 0x30))(plVar14);
                              }
                              if (plVar10 != (longlong *)0x0) {
                                *(undefined4 *)(plVar7 + 5) = 0x77;
                                plVar14 = (longlong *)FUN_23e914090(param_1,plVar15,plVar10);
                                lVar11 = *plVar15;
                                *plVar15 = lVar11 + -1;
                                if (lVar11 + -1 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))();
                                }
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                }
                                uVar4 = _DAT_23eea8f98;
                                if (plVar14 != (longlong *)0x0) {
                                  lVar11 = FUN_23e9001a0();
                                  if (lVar11 == 0) {
                                    FUN_23e915740(param_1,&plStack_68,_DAT_23eea8fa0);
                                    plStack_98 = plStack_68;
                                    lVar11 = *plVar14;
                                    *plVar14 = lVar11 + -1;
                                    if (lVar11 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    uVar17 = 0x78;
                                    plVar10 = plStack_58;
                                    plVar14 = DAT_23ed6a4f8;
                                    uStack_a0 = uStack_60;
                                    goto joined_r0x00023e11d704;
                                  }
                                  uVar12 = _PyDict_NewPresized(2);
                                  PyDict_SetItem(uVar12,uVar4,lVar11);
                                  PyDict_SetItem(uVar12,_DAT_23eea8f18,pcVar5);
                                  uVar4 = _DAT_23eeab050;
                                  *plVar16 = *plVar16 + 1;
                                  plStack_68 = plVar16;
                                  plVar10 = (longlong *)
                                            FUN_23e93e1e0(FUN_23e11e710,_DAT_23eea8fd0,
                                                          _DAT_23eea8fd8,uVar4,0,uVar12,
                                                          DAT_23eeab0a8,_DAT_23eea8fc8,&plStack_68,1
                                                         );
                                  *(undefined4 *)(plVar7 + 5) = 0x77;
                                  plVar15 = (longlong *)FUN_23e914090(param_1,plVar14,plVar10);
                                  lVar11 = *plVar14;
                                  *plVar14 = lVar11 + -1;
                                  if (lVar11 + -1 == 0) {
                                    (**(code **)(plVar14[1] + 0x30))();
                                  }
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                                  }
                                  if (plVar15 != (longlong *)0x0) {
                                    lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                    plVar7 = *(longlong **)(lVar11 + 0x28);
                                    plVar10 = (longlong *)plVar7[2];
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                         *(undefined8 *)(lVar11 + 0x30);
                                    *(undefined4 *)(plVar7 + 8) = 0xffffffff;
                                    if (plVar10 != (longlong *)0x0) {
                                      plVar7[2] = 0;
                                      *plVar10 = *plVar10 + -1;
                                      if (*plVar10 == 0) {
                                        (**(code **)(plVar10[1] + 0x30))();
                                      }
                                    }
                                    *plVar7 = *plVar7 + -1;
                                    if (*plVar7 == 0) {
                                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    }
                                    plVar7[0xf] = 0;
                                    *(longlong *)pcVar5 = *(longlong *)pcVar5 + 1;
                                    *plVar16 = *plVar16 + -1;
                                    if (*plVar16 == 0) {
                                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                                    }
                                    *plVar8 = *plVar8 + -1;
                                    if (*plVar8 == 0) {
                                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                                    }
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                                    }
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    *plVar15 = *plVar15 + -1;
                                    if (*plVar15 == 0) {
                                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                                    }
                                    *plVar1 = *plVar1 + -1;
                                    if (*plVar1 != 0) {
                                      return pcVar5;
                                    }
                                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                                    return pcVar5;
                                  }
                                }
                                goto LAB_23e11dcb0;
                              }
                            }
                            plStack_98 = *(longlong **)(param_1 + 0x60);
                            plVar10 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_a0 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          uVar17 = 0x77;
                          lVar11 = *plVar15;
                          *plVar15 = lVar11 + -1;
                          plVar14 = DAT_23ed6a4f8;
                          if (lVar11 + -1 == 0) {
                            FUN_23a334bc0();
                            uVar17 = 0x77;
                            plVar14 = DAT_23ed6a4f8;
                          }
                        }
                        goto joined_r0x00023e11d704;
                      }
                      goto LAB_23e11db88;
                    }
                    FUN_23e915740(param_1,&plStack_68,_DAT_23eea8fa0);
                    plStack_98 = plStack_68;
                    uStack_a0 = uStack_60;
                    lVar11 = *plVar14;
                    *plVar14 = lVar11 + -1;
                    if (lVar11 + -1 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    uVar17 = 0x52;
                    plVar10 = plStack_58;
                  }
                }
                plVar13 = (longlong *)0x0;
                plVar14 = DAT_23ed6a4f8;
                goto joined_r0x00023e11d704;
              }
              plStack_98 = *(longlong **)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_a0 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar11 = *plVar14;
              *plVar14 = lVar11 + -1;
              if (lVar11 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              uVar17 = 0x45;
            }
          }
          else {
            iVar6 = *(int *)(lVar11 + 0xc);
            if (*(int *)(lVar11 + 0xc) == 0) {
              *(int *)(lVar11 + 0xc) = _DAT_23ec14c7c;
              iVar6 = _DAT_23ec14c7c;
              _DAT_23ec14c7c = _DAT_23ec14c7c + 1;
            }
            if (_DAT_23ec14c78 != iVar6) {
              _DAT_23ec14c78 = iVar6;
              _DAT_23eeab038 =
                   FUN_23e8cbd60(lVar11,_DAT_23eea8f50,*(undefined8 *)(_DAT_23eea8f50 + 0x18));
            }
            if (-1 < _DAT_23eeab038) {
              lVar2 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
              lVar18 = *(longlong *)(lVar2 + 8 + _DAT_23eeab038 * 0x10);
              if (lVar18 != 0) goto LAB_23e11ccce;
              _DAT_23eeab038 =
                   FUN_23e8cbd60(lVar11,_DAT_23eea8f50,*(undefined8 *)(_DAT_23eea8f50 + 0x18));
              if (-1 < _DAT_23eeab038) {
                lVar18 = *(longlong *)(lVar2 + 8 + _DAT_23eeab038 * 0x10);
                goto LAB_23e11d8dc;
              }
            }
LAB_23e11d8f0:
            plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eea8f50);
            if ((plVar10 != (longlong *)0x0) && (lVar18 = *plVar10, lVar18 != 0))
            goto LAB_23e11ccce;
            FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f50);
            plStack_98 = plStack_68;
            uStack_a0 = uStack_60;
            plVar10 = plStack_58;
LAB_23e11d94d:
            lVar11 = *plVar14;
            *plVar14 = lVar11 + -1;
            if (lVar11 + -1 == 0) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            *plVar9 = *plVar9 + -1;
            uVar17 = 0x45;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
              uVar17 = 0x45;
            }
          }
        }
LAB_23e11d6fb:
        plVar13 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        plVar14 = DAT_23ed6a4f8;
        goto joined_r0x00023e11d704;
      }
LAB_23e11d490:
      plStack_98 = *(longlong **)(param_1 + 0x60);
      plStack_58 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_a0 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    uVar17 = 0x2f;
  }
  else {
    iVar6 = *(int *)(lVar11 + 0xc);
    if (*(int *)(lVar11 + 0xc) == 0) {
      *(int *)(lVar11 + 0xc) = _DAT_23ec14c7c;
      iVar6 = _DAT_23ec14c7c;
      _DAT_23ec14c7c = _DAT_23ec14c7c + 1;
    }
    if (_DAT_23ec14c74 != iVar6) {
      _DAT_23ec14c74 = iVar6;
      _DAT_23eeab028 = FUN_23e8cbd60(lVar11,_DAT_23eea8f08,*(undefined8 *)(_DAT_23eea8f08 + 0x18));
    }
    if (-1 < _DAT_23eeab028) {
      lVar2 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
      if (*(longlong *)(lVar2 + 8 + _DAT_23eeab028 * 0x10) != 0) goto LAB_23e11ca1e;
      _DAT_23eeab028 = FUN_23e8cbd60(lVar11,_DAT_23eea8f08,*(undefined8 *)(_DAT_23eea8f08 + 0x18));
      if (-1 < _DAT_23eeab028) {
        lVar11 = *(longlong *)(lVar2 + 8 + _DAT_23eeab028 * 0x10);
        goto LAB_23e11d868;
      }
    }
LAB_23e11d3d9:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eea8f08);
    if ((plVar9 != (longlong *)0x0) && (*plVar9 != 0)) goto LAB_23e11ca1e;
    FUN_23e915740(param_1,&plStack_68,_DAT_23eea8f08);
    uVar17 = 0x2f;
    plStack_98 = plStack_68;
    *plVar8 = *plVar8 + -1;
    uStack_a0 = uStack_60;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      uVar17 = 0x2f;
    }
  }
LAB_23e11d4bb:
  plVar13 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  plVar10 = plStack_58;
  plVar14 = DAT_23ed6a4f8;
joined_r0x00023e11d704:
  DAT_23ed6a4f8 = plVar14;
  if (plVar10 == (longlong *)0x0) {
    if (plVar14 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar14;
      *plVar14 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar15 = plVar14;
    }
    pcVar5 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar11 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar17;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar15[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar15 + -2;
    plVar15[-2] = lVar11;
    plVar15[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar15 + -2;
  }
  else {
    plVar15 = plVar10;
    if ((longlong *)plVar10[3] != plVar7) {
      if (plVar14 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar14;
        *plVar14 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar15 = plVar14;
      }
      pcVar5 = _PyRuntime_exref;
      plVar15[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      lVar11 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar17;
      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar2 = plVar15[-1];
      puVar3 = *(undefined8 **)(lVar11 + 8);
      *puVar3 = plVar15 + -2;
      plVar15[-2] = lVar11;
      plVar15[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar10;
      *(longlong **)(lVar11 + 8) = plVar15 + -2;
      plVar15[2] = (longlong)plVar10;
      if (lVar2 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar7,"ocoooo",plVar1,plVar16,plVar8,plVar9,plVar13,0);
  if (_DAT_23eeab060 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeab060 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar11 + 0x28);
  plVar10 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_98,uStack_a0,plVar15);
  return (code *)0x0;
}
