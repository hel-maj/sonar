/* ===== 23e7724a0 workers.fishing.fishing_bot:FishingBot._do_exit_fishing_on_pereves ===== */
/* ghidra_name=FUN_23e7724a0 entry=23e7724a0 size=3081 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7724a0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 uVar13;
  code *pcVar14;
  longlong *plVar15;
  undefined8 local_68;
  undefined8 local_60;
  longlong *local_58;
  
  plVar9 = _DAT_23eedad78;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedad78 == (longlong *)0x0) {
LAB_23e7724da:
    _DAT_23eedad78 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedafa8,DAT_23eedaeb8,0x10);
  }
  else {
    lVar11 = *_DAT_23eedad78;
    if (1 < lVar11) {
      *_DAT_23eedad78 = lVar11 + -1;
      goto LAB_23e7724da;
    }
    if (_DAT_23eedad78[2] != 0) {
      *_DAT_23eedad78 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e7724da;
    }
  }
  plVar3 = _DAT_23eedad78;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedad78 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eedad78[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar6 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar9 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = 0x563;
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar5 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    plVar10 = DAT_23ed6a4f8;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x563;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8d38);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 == (longlong *)0x0) {
      plVar9 = *(longlong **)(param_1 + 0x70);
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      plVar12 = (longlong *)0x0;
      uVar13 = 0x563;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = DAT_23ed6a4f8;
    }
    else {
      iVar8 = FUN_23a35f020(plVar10);
      lVar11 = *plVar10 + -1;
      if (iVar8 == -1) {
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar5 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar10 = lVar11;
        if (lVar11 == 0) {
          plVar12 = (longlong *)0x0;
          (**(code **)(plVar10[1] + 0x30))(plVar10);
          uVar13 = 0x563;
          plVar10 = DAT_23ed6a4f8;
        }
        else {
          uVar13 = 0x563;
          plVar12 = (longlong *)0x0;
          plVar10 = DAT_23ed6a4f8;
        }
      }
      else {
        *plVar10 = lVar11;
        if (lVar11 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        pcVar14 = _Py_NoneStruct_exref;
        if (iVar8 != 0) {
          lVar11 = *(longlong *)(param_1 + 0x38);
          lVar2 = *(longlong *)(lVar11 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar9 = *(longlong **)(lVar2 + 0x28);
          plVar3 = (longlong *)plVar9[2];
          *(undefined8 *)(lVar11 + 8) = *(undefined8 *)(lVar2 + 0x30);
          *(undefined4 *)(plVar9 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar9[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar9[0xf] = 0;
LAB_23e772ac2:
          *plVar1 = *plVar1 + -1;
          if (*plVar1 != 0) {
            return pcVar14;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar14;
        }
        cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_TrueStruct_exref);
        if (cVar7 == '\0') {
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar5 = *(undefined8 *)(param_1 + 0x68);
          plVar12 = (longlong *)0x0;
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar13 = 0x565;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar10 = DAT_23ed6a4f8;
        }
        else {
          lVar11 = FUN_23e8e0e20();
          if (lVar11 == 0) {
            FUN_23e915740(param_1,&local_68,DAT_23eed8988);
            uVar13 = 0x566;
            plVar12 = (longlong *)0x0;
            uVar6 = local_68;
            uVar5 = local_60;
            plVar9 = local_58;
            plVar10 = DAT_23ed6a4f8;
          }
          else {
            plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed95b0);
            if (plVar9 == (longlong *)0x0) {
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar13 = 0x566;
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar12 = (longlong *)0x0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar10 = DAT_23ed6a4f8;
            }
            else {
              cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              lVar11 = _DAT_23eed95b8;
              if (cVar7 == '\0') {
                uVar6 = *(undefined8 *)(param_1 + 0x60);
                plVar12 = (longlong *)0x0;
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar13 = 0x566;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar5 = *(undefined8 *)(param_1 + 0x68);
                plVar10 = DAT_23ed6a4f8;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x567;
                plVar9 = (longlong *)
                         FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar11 + 0x18));
                if (plVar9 == (longlong *)0x0) {
                  uVar6 = *(undefined8 *)(param_1 + 0x60);
                  uVar13 = 0x567;
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar12 = (longlong *)0x0;
                  uVar5 = *(undefined8 *)(param_1 + 0x68);
                  plVar10 = DAT_23ed6a4f8;
                }
                else {
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x56b;
                  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed95c0);
                  if (plVar9 == (longlong *)0x0) {
                    uVar6 = *(undefined8 *)(param_1 + 0x60);
                    uVar13 = 0x56b;
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar12 = (longlong *)0x0;
                    uVar5 = *(undefined8 *)(param_1 + 0x68);
                    plVar10 = DAT_23ed6a4f8;
                  }
                  else {
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
                    lVar11 = DAT_23eed8f48;
                    if (plVar9 == (longlong *)0x0) {
                      uVar6 = *(undefined8 *)(param_1 + 0x60);
                      uVar13 = 0x56e;
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar12 = (longlong *)0x0;
                      uVar5 = *(undefined8 *)(param_1 + 0x68);
                      plVar10 = DAT_23ed6a4f8;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x56e;
                      plVar12 = (longlong *)
                                FUN_23e915840(param_1,plVar9,DAT_23eed8c60,
                                              *(undefined8 *)(lVar11 + 0x18));
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar12 == (longlong *)0x0) {
                        uVar6 = *(undefined8 *)(param_1 + 0x60);
                        plVar12 = (longlong *)0x0;
                        plVar9 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar13 = 0x56e;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar5 = *(undefined8 *)(param_1 + 0x68);
                        plVar10 = DAT_23ed6a4f8;
                      }
                      else {
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        lVar11 = DAT_23eed8f50;
                        *(undefined4 *)(plVar3 + 5) = 0x56f;
                        plVar9 = (longlong *)
                                 FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                               *(undefined8 *)(lVar11 + 0x18));
                        if (plVar9 == (longlong *)0x0) {
                          uVar6 = *(undefined8 *)(param_1 + 0x60);
                          uVar13 = 0x56f;
                          plVar9 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plVar12 = (longlong *)0x0;
                          uVar5 = *(undefined8 *)(param_1 + 0x68);
                          plVar10 = DAT_23ed6a4f8;
                        }
                        else {
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
                          lVar11 = DAT_23eed8c68;
                          if (plVar9 == (longlong *)0x0) {
                            uVar6 = *(undefined8 *)(param_1 + 0x60);
                            uVar13 = 0x570;
                            plVar9 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar12 = (longlong *)0x0;
                            uVar5 = *(undefined8 *)(param_1 + 0x68);
                            plVar10 = DAT_23ed6a4f8;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x570;
                            plVar12 = (longlong *)
                                      FUN_23e915840(param_1,plVar9,DAT_23eed8c60,
                                                    *(undefined8 *)(lVar11 + 0x18));
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))(plVar9);
                            }
                            if (plVar12 == (longlong *)0x0) {
                              uVar6 = *(undefined8 *)(param_1 + 0x60);
                              plVar12 = (longlong *)0x0;
                              plVar9 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              uVar13 = 0x570;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                              plVar10 = DAT_23ed6a4f8;
                            }
                            else {
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                              }
                              lVar11 = DAT_23eed8ce0;
                              *(undefined4 *)(plVar3 + 5) = 0x571;
                              plVar9 = (longlong *)
                                       FUN_23e915840(param_1,plVar1,DAT_23eed8c50,
                                                     *(undefined8 *)(lVar11 + 0x18));
                              if (plVar9 == (longlong *)0x0) {
                                uVar6 = *(undefined8 *)(param_1 + 0x60);
                                uVar13 = 0x571;
                                plVar9 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plVar12 = (longlong *)0x0;
                                uVar5 = *(undefined8 *)(param_1 + 0x68);
                                plVar10 = DAT_23ed6a4f8;
                              }
                              else {
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed89b8,_Py_FalseStruct_exref);
                                if (cVar7 == '\0') {
                                  uVar6 = *(undefined8 *)(param_1 + 0x60);
                                  plVar12 = (longlong *)0x0;
                                  plVar9 = *(longlong **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  uVar13 = 0x573;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar5 = *(undefined8 *)(param_1 + 0x68);
                                  plVar10 = DAT_23ed6a4f8;
                                }
                                else {
                                  lVar11 = FUN_23e8e0e20();
                                  if (lVar11 == 0) {
                                    FUN_23e915740(param_1,&local_68,DAT_23eed8988);
                                    uVar13 = 0x574;
                                    plVar12 = (longlong *)0x0;
                                    uVar6 = local_68;
                                    uVar5 = local_60;
                                    plVar9 = local_58;
                                    plVar10 = DAT_23ed6a4f8;
                                  }
                                  else {
                                    plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eed8990);
                                    if (plVar9 == (longlong *)0x0) {
                                      uVar6 = *(undefined8 *)(param_1 + 0x60);
                                      uVar13 = 0x574;
                                      plVar9 = *(longlong **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      plVar12 = (longlong *)0x0;
                                      uVar5 = *(undefined8 *)(param_1 + 0x68);
                                      plVar10 = DAT_23ed6a4f8;
                                    }
                                    else {
                                      cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar9);
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                                      }
                                      lVar11 = _DAT_23eed95c8;
                                      if (cVar7 == '\0') {
                                        uVar6 = *(undefined8 *)(param_1 + 0x60);
                                        plVar12 = (longlong *)0x0;
                                        plVar9 = *(longlong **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        uVar13 = 0x574;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar5 = *(undefined8 *)(param_1 + 0x68);
                                        plVar10 = DAT_23ed6a4f8;
                                      }
                                      else {
                                        *(undefined4 *)(plVar3 + 5) = 0x575;
                                        plVar9 = (longlong *)
                                                 FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                               *(undefined8 *)(lVar11 + 0x18));
                                        if (plVar9 == (longlong *)0x0) {
                                          uVar6 = *(undefined8 *)(param_1 + 0x60);
                                          uVar13 = 0x575;
                                          plVar9 = *(longlong **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar12 = (longlong *)0x0;
                                          uVar5 = *(undefined8 *)(param_1 + 0x68);
                                          plVar10 = DAT_23ed6a4f8;
                                        }
                                        else {
                                          *plVar9 = *plVar9 + -1;
                                          if (*plVar9 == 0) {
                                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                                          }
                                          lVar11 = FUN_23e8e07b0();
                                          if (lVar11 == 0) {
                                            FUN_23e915740(param_1,&local_68,DAT_23eed8f68);
                                            uVar13 = 0x578;
                                            plVar12 = (longlong *)0x0;
                                            uVar6 = local_68;
                                            uVar5 = local_60;
                                            plVar9 = local_58;
                                            plVar10 = DAT_23ed6a4f8;
                                          }
                                          else {
                                            *(undefined4 *)(plVar3 + 5) = 0x578;
                                            plVar12 = (longlong *)FUN_23e91a870(param_1,lVar11);
                                            if (plVar12 == (longlong *)0x0) {
                                              uVar6 = *(undefined8 *)(param_1 + 0x60);
                                              uVar13 = 0x578;
                                              plVar9 = *(longlong **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                                              plVar10 = DAT_23ed6a4f8;
                                            }
                                            else {
                                              *(undefined4 *)(plVar3 + 5) = 0x579;
                                              plVar9 = (longlong *)
                                                       FUN_23e91bfe0(param_1,plVar12,_DAT_23eed95d0)
                                              ;
                                              if (plVar9 != (longlong *)0x0) {
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                                }
                                                lVar11 = *(longlong *)
                                                          (*(longlong *)(param_1 + 0x38) + 8);
                                                plVar9 = *(longlong **)(lVar11 + 0x28);
                                                plVar3 = (longlong *)plVar9[2];
                                                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                                     *(undefined8 *)(lVar11 + 0x30);
                                                *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                                                if (plVar3 != (longlong *)0x0) {
                                                  plVar9[2] = 0;
                                                  *plVar3 = *plVar3 + -1;
                                                  if (*plVar3 == 0) {
                                                    (**(code **)(plVar3[1] + 0x30))();
                                                  }
                                                }
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                                }
                                                plVar9[0xf] = 0;
                                                pcVar14 = _Py_NoneStruct_exref;
                                                *(longlong *)_Py_NoneStruct_exref =
                                                     *(longlong *)_Py_NoneStruct_exref + 1;
                                                *plVar12 = *plVar12 + -1;
                                                if (*plVar12 == 0) {
                                                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                                                }
                                                goto LAB_23e772ac2;
                                              }
                                              uVar6 = *(undefined8 *)(param_1 + 0x60);
                                              uVar13 = 0x579;
                                              plVar9 = *(longlong **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                                              plVar10 = DAT_23ed6a4f8;
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
        }
      }
    }
  }
  DAT_23ed6a4f8 = plVar10;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar14 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar14 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar10[-1];
    puVar4 = *(undefined8 **)(lVar11 + 8);
    *puVar4 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
    plVar15 = plVar10;
  }
  else {
    plVar15 = plVar9;
    if ((longlong *)plVar9[3] != plVar3) {
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar10;
        *plVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar14 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar11 = *(longlong *)(pcVar14 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
      lVar2 = plVar10[-1];
      puVar4 = *(undefined8 **)(lVar11 + 8);
      *puVar4 = plVar10 + -2;
      plVar10[-2] = lVar11;
      plVar10[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar9;
      *(longlong **)(lVar11 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar9;
      plVar15 = plVar10;
      if (lVar2 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5dd15,plVar1,plVar12);
  if (_DAT_23eedad78 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedad78 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar11 + 0x28);
  plVar3 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar5,plVar15);
  return (code *)0x0;
}
