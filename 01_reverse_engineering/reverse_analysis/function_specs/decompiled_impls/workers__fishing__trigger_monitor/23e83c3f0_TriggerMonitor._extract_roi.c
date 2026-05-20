/* ===== 23e83c3f0 workers.fishing.trigger_monitor:339 ===== */
/* ghidra_name=FUN_23e83c3f0 entry=23e83c3f0 size=3657 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e83c3f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined4 uVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  longlong lVar21;
  bool bVar22;
  undefined8 uStack_78;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = _DAT_23eede430;
  plVar1 = (longlong *)param_3[1];
  plVar2 = (longlong *)*param_3;
  if (_DAT_23eede430 == (longlong *)0x0) {
LAB_23e83c436:
    _DAT_23eede430 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede428,DAT_23eede5a0,0x28);
  }
  else {
    lVar11 = *_DAT_23eede430;
    if (1 < lVar11) {
      *_DAT_23eede430 = lVar11 + -1;
      goto LAB_23e83c436;
    }
    if (_DAT_23eede430[2] != 0) {
      *_DAT_23eede430 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e83c436;
    }
  }
  plVar3 = _DAT_23eede430;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eede430 + 9;
  lVar21 = *(longlong *)(lVar11 + 8);
  _DAT_23eede430[0xf] = lVar21;
  *(longlong **)(lVar11 + 8) = plVar10;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar6 = _DAT_23eedc0f8;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,uVar6);
  if (plVar10 == (longlong *)0x0) {
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x60);
    plVar10 = (longlong *)0x0;
    plVar18 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar13 = (longlong *)0x0;
    uVar17 = 0x156;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    goto LAB_23e83c970;
  }
  plStack_68 = plVar10;
  if ((code *)plVar10[1] == PyLong_Type_exref) {
    lVar11 = plVar10[2];
    lVar21 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
    lVar4 = *plVar10;
    if (lVar11 < 0) {
      lVar15 = -lVar11;
      lVar20 = lVar21;
      if (lVar11 == -1 || lVar15 < 1) {
        if (lVar21 < 0) {
          lVar20 = -lVar21;
          if (lVar21 == -1 || lVar20 < 1) {
            iVar9 = -(int)plVar10[3];
            goto LAB_23e83d1ab;
          }
          if (lVar4 != 1) goto LAB_23e83cf30;
LAB_23e83cf01:
          plVar12 = (longlong *)FUN_23e8be680(plVar10,DAT_23ed6ccf8 + 0x18,lVar20);
          lVar11 = -plVar12[2];
          if (-1 < lVar11) {
            lVar11 = plVar12[2];
          }
          plVar12[2] = lVar11;
          goto LAB_23e83c50c;
        }
        if (lVar21 < 2) {
          iVar9 = -(int)plVar10[3];
          goto LAB_23e83cf5b;
        }
        if (lVar4 != 1) goto LAB_23e83cd1d;
      }
      else {
        lVar20 = -lVar21;
        if (-lVar21 < 0) {
          lVar20 = lVar21;
        }
        if (lVar4 != 1) {
          if (lVar21 < 0) {
LAB_23e83cf30:
            plVar12 = (longlong *)FUN_23e8be550(plVar10 + 3,lVar15,DAT_23ed6ccf8 + 0x18,lVar20);
            plVar12[2] = -plVar12[2];
          }
          else {
LAB_23e83cd1d:
            plVar12 = (longlong *)FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar20,plVar10 + 3,lVar15);
          }
          goto LAB_23e83c8df;
        }
        if (lVar21 < 0) goto LAB_23e83cf01;
      }
      plVar12 = (longlong *)FUN_23e8beb80(plVar10,DAT_23ed6ccf8 + 0x18,lVar20,0xffffffff);
    }
    else {
      if (lVar11 < 2) {
        if (lVar21 < 0) {
          lVar20 = -lVar21;
          if (lVar21 != -1 && 0 < lVar20) {
            if (lVar4 == 1) goto LAB_23e83d216;
            goto LAB_23e83cd7a;
          }
          iVar9 = 0;
          if (lVar11 != 0) {
            iVar9 = (int)plVar10[3];
          }
LAB_23e83d1ab:
          iVar9 = iVar9 - *(int *)(DAT_23ed6ccf8 + 0x18);
        }
        else {
          if (1 < lVar21) {
            if (lVar4 == 1) goto LAB_23e83d07d;
            goto LAB_23e83c8cc;
          }
          iVar9 = 0;
          if (lVar11 != 0) {
            iVar9 = (int)plVar10[3];
          }
LAB_23e83cf5b:
          if (lVar21 != 0) {
            iVar9 = iVar9 + *(int *)(DAT_23ed6ccf8 + 0x18);
          }
        }
        if (lVar4 == 1) {
          FUN_23e8be320(&plStack_68,iVar9);
          plVar12 = plStack_68;
          goto LAB_23e83c50c;
        }
        plVar12 = (longlong *)FUN_23e8bb5f0();
      }
      else {
        lVar20 = -lVar21;
        if (-lVar21 < 0) {
          lVar20 = lVar21;
        }
        if (lVar4 == 1) {
          bVar22 = lVar21 < 0;
          lVar21 = lVar20;
          if (bVar22) {
LAB_23e83d216:
            plVar12 = (longlong *)FUN_23e8beb80(plVar10,DAT_23ed6ccf8 + 0x18,lVar20,1);
          }
          else {
LAB_23e83d07d:
            plVar12 = (longlong *)FUN_23e8be680(plVar10,DAT_23ed6ccf8 + 0x18,lVar21);
          }
          goto LAB_23e83c50c;
        }
        bVar22 = lVar21 < 0;
        lVar21 = lVar20;
        if (bVar22) {
LAB_23e83cd7a:
          plVar12 = (longlong *)FUN_23e8be900(plVar10 + 3,lVar11,DAT_23ed6ccf8 + 0x18,lVar20);
          goto LAB_23e83c8df;
        }
LAB_23e83c8cc:
        plVar12 = (longlong *)FUN_23e8be550(plVar10 + 3,lVar11,DAT_23ed6ccf8 + 0x18,lVar21);
        if (plVar12 == (longlong *)0x0) goto LAB_23e83c930;
      }
LAB_23e83c8df:
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
LAB_23e83c50c:
    cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0f8,plVar12);
    if (cVar8 != '\0') {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar11 = FUN_23e8db3c0();
      if (lVar11 == 0) {
        plVar10 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        FUN_23e915740(param_1,&plStack_68,_DAT_23eedc100);
        uVar17 = 0x157;
        uStack_78 = uStack_60;
        plVar12 = (longlong *)0x0;
        plVar18 = plStack_58;
        plVar14 = plStack_68;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x157;
        plVar12 = (longlong *)FUN_23e91bfe0(param_1,lVar11);
        if (plVar12 == (longlong *)0x0) {
          uStack_78 = *(undefined8 *)(param_1 + 0x68);
          plVar14 = *(longlong **)(param_1 + 0x60);
          plVar10 = (longlong *)0x0;
          plVar18 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar13 = (longlong *)0x0;
          uVar17 = 0x157;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        else {
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc108);
          if (plVar10 == (longlong *)0x0) {
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            plVar14 = *(longlong **)(param_1 + 0x60);
            plVar13 = (longlong *)0x0;
            plVar18 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar17 = 0x158;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar10 = (longlong *)0x0;
          }
          else {
            plVar13 = (longlong *)FUN_23e8c6640(plVar12,plVar10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar13 == (longlong *)0x0) {
              uStack_78 = *(undefined8 *)(param_1 + 0x68);
              plVar14 = *(longlong **)(param_1 + 0x60);
              plVar10 = (longlong *)0x0;
              plVar18 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar17 = 0x158;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              iVar9 = FUN_23e97d950(plVar13,DAT_23ed6cd18);
              if (iVar9 == -1) {
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                plVar14 = *(longlong **)(param_1 + 0x60);
                plVar10 = (longlong *)0x0;
                plVar18 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar17 = 0x159;
                *(undefined8 *)(param_1 + 0x70) = 0;
              }
              else {
                if (iVar9 == 1) {
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc0f8);
                  if (plVar10 == (longlong *)0x0) {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    uVar17 = 0x15a;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar10 = (longlong *)0x0;
                    goto LAB_23e83c970;
                  }
                  plVar14 = (longlong *)FUN_23e8c6f80(plVar10,plVar13);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar14 == (longlong *)0x0) {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    plVar10 = (longlong *)0x0;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar17 = 0x15a;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    goto LAB_23e83c970;
                  }
                  cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eedc110,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (cVar8 == '\0') {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    plVar10 = (longlong *)0x0;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar17 = 0x15a;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    goto LAB_23e83c970;
                  }
                  cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eedc0f8,DAT_23ed6ccf0);
                  if (cVar8 == '\0') {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    plVar10 = (longlong *)0x0;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar17 = 0x15b;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    goto LAB_23e83c970;
                  }
                  cVar8 = FUN_23e8d9ac0(plVar2,_DAT_23eedc108,plVar12);
                  if (cVar8 == '\0') {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    plVar10 = (longlong *)0x0;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar17 = 0x15c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    goto LAB_23e83c970;
                  }
                }
                lVar21 = DAT_23ed6cce8;
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar14 = *(longlong **)(DAT_23ed6cce8 + 0x20);
                iVar9 = *(int *)(lVar11 + 0x1410);
                *plVar14 = *plVar14 + 1;
                if (iVar9 == 0) {
                  plVar10 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
                  plVar14 = *(longlong **)(lVar21 + 0x20);
                }
                else {
                  iVar9 = iVar9 + -1;
                  *(int *)(lVar11 + 0x1410) = iVar9;
                  plVar10 = *(longlong **)(lVar11 + 0x1190 + (longlong)iVar9 * 8);
                  *plVar10 = 1;
                }
                lVar11 = *(longlong *)(lVar21 + 0x28);
                plVar10[2] = 0;
                plVar10[4] = (longlong)plVar14;
                plVar10[5] = lVar11;
                uVar6 = _DAT_23eedc2c0;
                plVar10[3] = 1;
                *(undefined4 *)(plVar3 + 5) = 0x161;
                plVar14 = (longlong *)FUN_23e915840(param_1,plVar2,uVar6,plVar1);
                if (plVar14 == (longlong *)0x0) {
                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                  plVar14 = *(longlong **)(param_1 + 0x60);
                  uVar17 = 0x161;
                  plVar18 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                else {
                  PyDict_SetItem(plVar10,_DAT_23eedc2c8,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x162;
                  plVar14 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eedc2d0,plVar1);
                  if (plVar14 == (longlong *)0x0) {
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x60);
                    uVar17 = 0x162;
                    plVar18 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    PyDict_SetItem(plVar10,_DAT_23eedc2d8,plVar14);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x163;
                    plVar14 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eedc2e0,plVar1);
                    if (plVar14 == (longlong *)0x0) {
                      uStack_78 = *(undefined8 *)(param_1 + 0x68);
                      plVar14 = *(longlong **)(param_1 + 0x60);
                      uVar17 = 0x163;
                      plVar18 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                    }
                    else {
                      PyDict_SetItem(plVar10,_DAT_23eedc198,plVar14);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      *(undefined4 *)(plVar3 + 5) = 0x164;
                      plVar14 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eedc2e8,plVar1);
                      if (plVar14 == (longlong *)0x0) {
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        plVar14 = *(longlong **)(param_1 + 0x60);
                        uVar17 = 0x164;
                        plVar18 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                      }
                      else {
                        PyDict_SetItem(plVar10,_DAT_23eedc2f0,plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          (**(code **)(plVar14[1] + 0x30))(plVar14);
                        }
                        *(undefined4 *)(plVar3 + 5) = 0x165;
                        plVar14 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eedc2f8,plVar1);
                        if (plVar14 == (longlong *)0x0) {
                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                          plVar14 = *(longlong **)(param_1 + 0x60);
                          uVar17 = 0x165;
                          plVar18 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                        }
                        else {
                          PyDict_SetItem(plVar10,_DAT_23eedc300,plVar14);
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedc110);
                          if (plVar14 != (longlong *)0x0) {
                            PyDict_SetItem(plVar10,_DAT_23eedc308,plVar14);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                            plVar3 = *(longlong **)(lVar11 + 0x28);
                            plVar14 = (longlong *)plVar3[2];
                            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                 *(undefined8 *)(lVar11 + 0x30);
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
                            *plVar10 = *plVar10 + 1;
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))(plVar13);
                            }
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))(plVar2);
                            }
                            lVar11 = *plVar1;
                            *plVar1 = lVar11 + -1;
                            if (lVar11 + -1 != 0) {
                              return plVar10;
                            }
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                            return plVar10;
                          }
                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                          plVar14 = *(longlong **)(param_1 + 0x60);
                          uVar17 = 0x166;
                          plVar18 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
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
      goto LAB_23e83c970;
    }
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x60);
    plVar18 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = plVar12;
  }
  else {
    cVar8 = FUN_23e8c7160(&plStack_68);
    plVar12 = plStack_68;
    if (cVar8 != '\0') goto LAB_23e83c50c;
LAB_23e83c930:
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    plVar18 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar14 = *(longlong **)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  uVar17 = 0x156;
  plVar10 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
LAB_23e83c970:
  plVar16 = DAT_23ed6a4f8;
  if (plVar18 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar18 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar16 + 0x24) = uVar17;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar21 = plVar16[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar16 + -2;
    plVar16[-2] = lVar11;
    plVar16[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar16 + -2;
    plVar19 = plVar16;
  }
  else {
    plVar19 = plVar18;
    if ((longlong *)plVar18[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar19 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar16[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar16 + 0x24) = uVar17;
      pcVar7 = _PyRuntime_exref;
      *(undefined4 *)(plVar16 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
      lVar21 = plVar16[-1];
      puVar5 = *(undefined8 **)(lVar11 + 8);
      *puVar5 = plVar16 + -2;
      plVar16[-2] = lVar11;
      plVar16[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar5;
      lVar21 = *plVar18;
      *(longlong **)(lVar11 + 8) = plVar16 + -2;
      plVar16[2] = (longlong)plVar18;
      plVar19 = plVar16;
      if (lVar21 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
    }
  }
  FUN_23e8bba40(plVar3,"ooooo",plVar2,plVar1,plVar12,plVar13,plVar10);
  if (_DAT_23eede430 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede430 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar18 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar18 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar11 = *plVar1;
  *plVar1 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar14,uStack_78,plVar19);
  return (longlong *)0x0;
}
