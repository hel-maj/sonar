/* ===== 23aaa88f0 __main__:165 ===== */
/* ghidra_name=FUN_23aaa88f0 entry=23aaa88f0 size=3492 */

/* WARNING: Type propagation algorithm not settling */

code * FUN_23aaa88f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  code *pcVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  longlong *plVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  longlong **pplStack_230;
  undefined8 uStack_228;
  longlong *plStack_218;
  undefined8 uStack_210;
  longlong *plStack_208;
  longlong *plStack_1f8;
  undefined8 uStack_1f0;
  longlong *plStack_1e0;
  longlong *plStack_1d8;
  longlong lStack_1d0;
  longlong *plStack_1c8;
  longlong *plStack_1c0;
  longlong *plStack_1b8;
  longlong *plStack_1b0;
  undefined8 *puStack_1a8;
  longlong *plStack_180;
  longlong *plStack_178;
  longlong *plStack_170;
  longlong **pplStack_158;
  longlong *plStack_150;
  undefined8 uStack_148;
  longlong *plStack_140;
  undefined8 uStack_138;
  longlong *plStack_130;
  longlong *plStack_120;
  undefined8 uStack_118;
  longlong *plStack_108;
  longlong lStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  undefined8 *puStack_d8;
  undefined8 *puStack_d0;
  longlong *local_a8;
  code *local_90;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar6 = DAT_23ed90c90;
  plVar13 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23ed90c90 == (longlong *)0x0) {
LAB_23aaa8944:
    puStack_d0 = (undefined8 *)0x23aaa8960;
    DAT_23ed90c90 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90c88,DAT_23ed90d18,0x18);
  }
  else {
    lVar10 = *DAT_23ed90c90;
    if (1 < lVar10) {
      *DAT_23ed90c90 = lVar10 + -1;
      goto LAB_23aaa8944;
    }
    if (DAT_23ed90c90[2] != 0) {
      *DAT_23ed90c90 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        puStack_d0 = (undefined8 *)0x23aaa8eb2;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23aaa8944;
    }
  }
  plVar2 = DAT_23ed90c90;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar6 = DAT_23ed90c90 + 9;
  lVar15 = *(longlong *)(lVar10 + 8);
  DAT_23ed90c90[0xf] = lVar15;
  *(longlong **)(lVar10 + 8) = plVar6;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar22 = DAT_23ed8fd58;
  *(undefined4 *)(plVar2 + 8) = 0;
  puStack_d0 = (undefined8 *)0x23aaa89d6;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,uVar22);
  if (plVar6 == (longlong *)0x0) {
LAB_23aaa8c90:
    plVar7 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar22 = *(undefined8 *)(param_1 + 0x60);
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar2 + 5) = 0xae;
    puStack_d0 = (undefined8 *)0x23aaa89fb;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,DAT_23ed8fd90);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_d0 = (undefined8 *)0x23aaa8c7a;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
      if (plVar7 != (longlong *)0x0) goto LAB_23aaa8a11;
      goto LAB_23aaa8c90;
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23aaa8c90;
LAB_23aaa8a11:
    puStack_d0 = (undefined8 *)0x23aaa8a19;
    plVar6 = (longlong *)FUN_23a388310(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_d0 = (undefined8 *)0x23aaa8e8a;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar6 == (longlong *)0x0) goto LAB_23aaa8c90;
    puStack_d0 = (undefined8 *)0x23aaa8a43;
    plVar8 = (longlong *)(**(code **)(plVar6[1] + 0xe0))(plVar6);
    if (plVar8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aaa8ef4;
      plVar8 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2);
      if (plVar8 != (longlong *)0x0) goto LAB_23aaa8a4f;
      plVar9 = (longlong *)0x0;
    }
    else {
LAB_23aaa8a4f:
      puStack_d0 = (undefined8 *)0x23aaa8a5d;
      plVar9 = (longlong *)(**(code **)(plVar6[1] + 0xe0))(plVar6);
      if (plVar9 == (longlong *)0x0) {
        puStack_d0 = (undefined8 *)0x23aaa9247;
        plVar9 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2);
        if (plVar9 == (longlong *)0x0) goto LAB_23aaa8f10;
      }
      puStack_d0 = (undefined8 *)0x23aaa8a7d;
      cVar4 = FUN_23a3884a0(param_1,local_78,plVar6,2);
      if (cVar4 != '\0') {
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          puStack_d0 = (undefined8 *)0x23aaa8a97;
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        if (*plVar8 == 0) {
          puStack_d0 = (undefined8 *)0x23aaa8aa7;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (*plVar9 == 0) {
          puStack_d0 = (undefined8 *)0x23aaa8faa;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        puStack_d0 = (undefined8 *)0x23aaa8aba;
        iVar5 = FUN_23a35f020(plVar8);
        if (iVar5 == -1) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          uVar20 = 0xb0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23aaa8cbd;
        }
        if (iVar5 == 0) {
          puStack_d0 = (undefined8 *)0x23aaa8fc5;
          lVar10 = FUN_23ebc0cf0();
          if (lVar10 == 0) {
            uVar20 = 0xb4;
            puStack_d0 = (undefined8 *)0x23aaa9618;
            FUN_23e915740(param_1,local_78,DAT_23ed8fba8);
            goto LAB_23aaa8cbd;
          }
          puStack_d0 = (undefined8 *)0x23aaa8fdd;
          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fc80);
          plVar6 = DAT_23ed8fda0;
          if (plVar7 == (longlong *)0x0) {
LAB_23aaa9548:
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            uVar20 = 0xb4;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23aaa8cbd;
          }
          lVar10 = *(longlong *)(param_1 + 0x10);
          plVar14 = *(longlong **)(lVar10 + 0xe20);
          local_90 = (code *)plVar7;
          if (plVar14 == (longlong *)0x0) {
            puStack_d0 = (undefined8 *)0x23aaa93d6;
            plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar15 = plVar14[3];
            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
            *(longlong *)(lVar10 + 0xe20) = lVar15;
            *plVar14 = 1;
          }
          pcVar11 = _PyRuntime_exref;
          plVar14[4] = 0;
          lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
          lVar15 = plVar14[-1];
          puVar17 = *(undefined8 **)(lVar10 + 8);
          *puVar17 = plVar14 + -2;
          plVar14[-2] = lVar10;
          plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
          *(longlong **)(lVar10 + 8) = plVar14 + -2;
          *plVar6 = *plVar6 + 1;
          plVar14[3] = (longlong)plVar6;
          uVar22 = DAT_23ed6cd28;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            puStack_d0 = (undefined8 *)0x23aaa95dc;
            plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar6 == (longlong *)0x0) goto LAB_23aaa9713;
            *plVar6 = *plVar6 + 1;
            DAT_23ed6a4c0 = plVar6;
          }
          uStack_80 = uVar22;
          puStack_d0 = (undefined8 *)0x23aaa90b4;
          local_88 = plVar9;
          lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
          if (lVar10 == 0) {
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa9523;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa9535;
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            uVar20 = 0xb4;
            goto LAB_23aaa8cbd;
          }
          plVar14[4] = lVar10;
          puStack_d0 = (undefined8 *)0x23aaa90d9;
          plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            puStack_d0 = (undefined8 *)0x23aaa9363;
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar6 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0xb4;
            puStack_d0 = (undefined8 *)0x23aaa910f;
            plVar7 = (longlong *)FUN_23e914090(param_1,local_90,plVar6);
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa9127;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa93aa;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (plVar7 != (longlong *)0x0) {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa93bb;
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              *(undefined4 *)(plVar2 + 5) = 0xb7;
              puStack_d0 = (undefined8 *)0x23aaa915e;
              pcVar11 = (code *)FUN_23e91bfe0(param_1,plVar13,DAT_23ed8fda8);
              if (pcVar11 == (code *)0x0) {
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar20 = 0xb7;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23aaa8cbd;
              }
              goto LAB_23aaa9167;
            }
            goto LAB_23aaa9548;
          }
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0xb4;
          uVar20 = 0xb4;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong *)local_90 = *(longlong *)local_90 + -1;
          lVar10 = *(longlong *)local_90;
joined_r0x00023aaa968d:
          if (lVar10 == 0) {
            puStack_d0 = (undefined8 *)0x23aaa969d;
            (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            uVar20 = uVar19;
          }
        }
        else {
          puStack_d0 = (undefined8 *)0x23aaa8ad0;
          lVar10 = FUN_23ebc0cf0();
          if (lVar10 == 0) {
            uVar20 = 0xb1;
            puStack_d0 = (undefined8 *)0x23aaa9640;
            FUN_23e915740(param_1,local_78,DAT_23ed8fba8);
            goto LAB_23aaa8cbd;
          }
          puStack_d0 = (undefined8 *)0x23aaa8ae8;
          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fbb0);
          plVar6 = DAT_23ed8fd98;
          if (plVar7 != (longlong *)0x0) {
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar10 + 0xe20);
            local_90 = (code *)plVar7;
            if (plVar14 == (longlong *)0x0) {
              puStack_d0 = (undefined8 *)0x23aaa93fe;
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar15 = plVar14[3];
              *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
              *(longlong *)(lVar10 + 0xe20) = lVar15;
              *plVar14 = 1;
            }
            pcVar11 = _PyRuntime_exref;
            plVar14[4] = 0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
            lVar15 = plVar14[-1];
            puVar17 = *(undefined8 **)(lVar10 + 8);
            *puVar17 = plVar14 + -2;
            plVar14[-2] = lVar10;
            plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
            *(longlong **)(lVar10 + 8) = plVar14 + -2;
            *plVar6 = *plVar6 + 1;
            plVar14[3] = (longlong)plVar6;
            uVar22 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              puStack_d0 = (undefined8 *)0x23aaa959c;
              plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar6 == (longlong *)0x0) {
LAB_23aaa9713:
                puStack_d0 = (undefined8 *)0x23aaa971b;
                PyErr_PrintEx(0,0);
                lVar10 = 1;
                puStack_d0 = (undefined8 *)0x23aaa9726;
                Py_Exit();
                plVar16 = DAT_23ed90c80;
                puStack_d0 = &DAT_23ed6cce0;
                puStack_d8 = &DAT_23ed6a4c0;
                plVar6 = (longlong *)*puVar17;
                plVar7 = (longlong *)puVar17[1];
                plStack_120 = plVar9;
                uStack_118 = uVar22;
                plStack_108 = plVar2;
                lStack_100 = param_1;
                plStack_f8 = plVar8;
                plStack_f0 = plVar9;
                plStack_e8 = plVar14;
                plStack_e0 = plVar13;
                if (DAT_23ed90c80 == (longlong *)0x0) {
LAB_23aaa9779:
                  puStack_1a8 = (undefined8 *)0x23aaa9795;
                  DAT_23ed90c80 = (longlong *)FUN_23e91f3b0(lVar10,DAT_23ed90c78,DAT_23ed90d18,0x28)
                  ;
                }
                else {
                  lVar15 = *DAT_23ed90c80;
                  if (1 < lVar15) {
                    *DAT_23ed90c80 = lVar15 + -1;
                    goto LAB_23aaa9779;
                  }
                  if (DAT_23ed90c80[2] != 0) {
                    *DAT_23ed90c80 = lVar15 + -1;
                    if (lVar15 + -1 == 0) {
                      puStack_1a8 = (undefined8 *)0x23aaa9b02;
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    goto LAB_23aaa9779;
                  }
                }
                plVar2 = DAT_23ed90c80;
                lVar15 = *(longlong *)(lVar10 + 0x38);
                plVar13 = DAT_23ed90c80 + 9;
                lVar12 = *(longlong *)(lVar15 + 8);
                DAT_23ed90c80[0xf] = lVar12;
                *(longlong **)(lVar15 + 8) = plVar13;
                if (((lVar12 != 0) &&
                    ((*(char *)(lVar12 + 0x45) == '\x01' ||
                     ((ulonglong)
                      (*(longlong *)(lVar12 + 0x20) + 0xb8 +
                      (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
                      *(ulonglong *)(lVar12 + 0x38))))) && (plVar2[0xe] != 0)) {
                  plVar13 = *(longlong **)(lVar12 + 0x28);
                  *(longlong **)(plVar2[0xe] + 0x10) = plVar13;
                  if (plVar13 != (longlong *)0x0) {
                    *plVar13 = *plVar13 + 1;
                  }
                }
                *plVar2 = *plVar2 + 1;
                *(undefined4 *)(plVar2 + 8) = 0;
                puStack_1a8 = (undefined8 *)0x23aaa9801;
                lVar12 = FUN_23ebc0cf0();
                lVar15 = DAT_23ed8fdb8;
                if (lVar12 == 0) {
                  plVar9 = (longlong *)0x0;
                  plVar14 = (longlong *)0x0;
                  puStack_1a8 = (undefined8 *)0x23aaaa2b9;
                  FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fba8);
                  uVar20 = 0xc3;
                  plVar8 = (longlong *)0x0;
                  plVar13 = plStack_130;
                  plVar16 = DAT_23ed6a4f8;
                  pplStack_158 = (longlong **)uStack_138;
                  plStack_150 = plStack_140;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aaa9f83;
                }
                *(undefined4 *)(plVar2 + 5) = 0xc3;
                puStack_1a8 = (undefined8 *)0x23aaa9831;
                plVar13 = (longlong *)
                          FUN_23e915840(lVar10,lVar12,DAT_23ed8fbb0,*(undefined8 *)(lVar15 + 0x18));
                if (plVar13 == (longlong *)0x0) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  plVar14 = (longlong *)0x0;
                  uVar20 = 0xc3;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = (longlong *)0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aaa9f83;
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aaa9ada;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                puStack_1a8 = (undefined8 *)0x23aaa984f;
                iVar5 = FUN_23a35f020(plVar7);
                if (iVar5 == -1) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar9 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar20 = 0xc6;
                  plVar14 = (longlong *)0x0;
                  plVar8 = (longlong *)0x0;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                  goto joined_r0x00023aaa9f83;
                }
                plVar8 = (longlong *)0x0;
                if (iVar5 != 0) {
                  puStack_1a8 = (undefined8 *)0x23aaa9b15;
                  lVar15 = FUN_23ebc0ba0();
                  if (lVar15 == 0) {
                    plVar9 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aaaa611;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fdc0);
                    uVar20 = 199;
                    plVar8 = (longlong *)0x0;
                    plVar13 = plStack_130;
                    plVar16 = DAT_23ed6a4f8;
                    pplStack_158 = (longlong **)uStack_138;
                    plStack_150 = plStack_140;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aaa9f83;
                  }
                  *(undefined4 *)(plVar2 + 5) = 199;
                  puStack_1a8 = (undefined8 *)0x23aaa9b33;
                  plVar8 = (longlong *)FUN_23e91a870(lVar10,lVar15);
                  if (plVar8 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    plVar14 = (longlong *)0x0;
                    uVar20 = 199;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aaa9f83;
                  }
                  puStack_1a8 = (undefined8 *)0x23aaa9b4e;
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8fdc8);
                  if (plVar16 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar14 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar20 = 200;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar9 = (longlong *)0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aaa9f83;
                  }
                  puStack_1a8 = (undefined8 *)0x23aaa9b5f;
                  lVar15 = FUN_23ebc0ba0();
                  if (lVar15 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aaaa694;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fdc0);
                    *plVar16 = *plVar16 + -1;
                    lVar15 = *plVar16;
                    plStack_150 = plStack_140;
                    pplStack_158 = (longlong **)uStack_138;
                    plVar13 = plStack_130;
                  }
                  else {
                    puStack_1a8 = (undefined8 *)0x23aaa9b7a;
                    plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ed8fdd0);
                    if (plVar13 != (longlong *)0x0) {
                      puStack_1a8 = (undefined8 *)0x23aaa9b95;
                      plVar9 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fdd8);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaa9ba8;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (plVar9 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          plVar14 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          puStack_1a8 = (undefined8 *)0x23aaaa700;
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                          uVar20 = 200;
                          plVar16 = DAT_23ed6a4f8;
                          plVar3 = uStack_148;
                        }
                        else {
                          plVar9 = (longlong *)0x0;
                          plVar14 = (longlong *)0x0;
                          uVar20 = 200;
                          plVar16 = DAT_23ed6a4f8;
                          plVar3 = uStack_148;
                        }
                        goto joined_r0x00023aaa9f83;
                      }
                      *(undefined4 *)(plVar2 + 5) = 200;
                      puStack_1a8 = (undefined8 *)0x23aaa9bc6;
                      plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaa9bda;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaa9bec;
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 200;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aaa9f83;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaaa4aa;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      lVar15 = DAT_23ed8fde8;
                      *(undefined4 *)(plVar2 + 5) = 0xc9;
                      puStack_1a8 = (undefined8 *)0x23aaa9c23;
                      plVar13 = (longlong *)
                                FUN_23e915840(lVar10,plVar8,DAT_23ed8fde0,
                                              *(undefined8 *)(lVar15 + 0x18));
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xc9;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aaa9f83;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaaa4ca;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      lVar15 = DAT_23ed8fdf8;
                      *(undefined4 *)(plVar2 + 5) = 0xca;
                      puStack_1a8 = (undefined8 *)0x23aaa9c5d;
                      puVar17 = DAT_23ed8fdf0;
                      plVar13 = (longlong *)
                                FUN_23e915840(lVar10,plVar8,DAT_23ed8fdf0,
                                              *(undefined8 *)(lVar15 + 0x18));
                      if (plVar13 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar9 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xca;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar14 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aaa9f83;
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        puStack_1a8 = (undefined8 *)0x23aaaa4da;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      puStack_1a8 = (undefined8 *)0x23aaa9c82;
                      plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8fe00);
                      uVar22 = DAT_23ed6cd28;
                      if (plVar16 == (longlong *)0x0) {
                        plStack_150 = *(longlong **)(lVar10 + 0x60);
                        plVar13 = *(longlong **)(lVar10 + 0x70);
                        plVar14 = (longlong *)0x0;
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        uVar20 = 0xcb;
                        pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plVar9 = (longlong *)0x0;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                        goto joined_r0x00023aaa9f83;
                      }
                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                        puStack_1a8 = (undefined8 *)0x23aaaa817;
                        plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                        if (plVar13 == (longlong *)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aaaaac3;
                          PyErr_PrintEx(0,0);
                          lVar15 = 1;
                          puStack_1a8 = (undefined8 *)0x23aaaaace;
                          Py_Exit();
                          plVar3 = DAT_23ed90c68;
                          puStack_1a8 = &DAT_23ed6a4c0;
                          uStack_1f0 = uVar22;
                          plVar13 = (longlong *)*puVar17;
                          plVar14 = (longlong *)puVar17[1];
                          plStack_1f8 = plVar7;
                          plStack_1e0 = plVar2;
                          plStack_1d8 = plVar8;
                          lStack_1d0 = lVar10;
                          plStack_1c8 = plVar16;
                          plStack_1c0 = plVar9;
                          plStack_1b8 = plVar7;
                          plStack_1b0 = plVar6;
                          if (DAT_23ed90c68 == (longlong *)0x0) {
LAB_23aaaab16:
                            DAT_23ed90c68 =
                                 (longlong *)FUN_23e91f3b0(lVar15,DAT_23ed90c60,DAT_23ed90d18,0x20);
                          }
                          else {
                            lVar10 = *DAT_23ed90c68;
                            if (1 < lVar10) {
                              *DAT_23ed90c68 = lVar10 + -1;
                              goto LAB_23aaaab16;
                            }
                            if (DAT_23ed90c68[2] != 0) {
                              *DAT_23ed90c68 = lVar10 + -1;
                              if (lVar10 + -1 == 0) {
                                (**(code **)(plVar3[1] + 0x30))(plVar3);
                              }
                              goto LAB_23aaaab16;
                            }
                          }
                          plVar2 = DAT_23ed90c68;
                          lVar10 = *(longlong *)(lVar15 + 0x38);
                          plVar6 = DAT_23ed90c68 + 9;
                          lVar12 = *(longlong *)(lVar10 + 8);
                          DAT_23ed90c68[0xf] = lVar12;
                          *(longlong **)(lVar10 + 8) = plVar6;
                          if (((lVar12 != 0) &&
                              ((*(char *)(lVar12 + 0x45) == '\x01' ||
                               ((ulonglong)
                                (*(longlong *)(lVar12 + 0x20) + 0xb8 +
                                (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
                                *(ulonglong *)(lVar12 + 0x38))))) && (plVar2[0xe] != 0)) {
                            plVar6 = *(longlong **)(lVar12 + 0x28);
                            *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
                            if (plVar6 != (longlong *)0x0) {
                              *plVar6 = *plVar6 + 1;
                            }
                          }
                          *plVar2 = *plVar2 + 1;
                          *(undefined4 *)(plVar2 + 8) = 0;
                          lVar10 = FUN_23ebc0cf0();
                          if (lVar10 == 0) {
                            plVar8 = (longlong *)0x0;
                            FUN_23e915740(lVar15,&plStack_218,DAT_23ed8fba8);
                            uVar20 = 0xe6;
                            pplStack_230 = (longlong **)plStack_218;
                            uStack_228 = uStack_210;
                            plVar7 = (longlong *)0x0;
                            plVar6 = plStack_208;
                            goto LAB_23aaab0d0;
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23ed8fbe0);
                          plVar6 = DAT_23ed8fe60;
                          if (plVar7 == (longlong *)0x0) {
                            pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                            plVar6 = *(longlong **)(lVar15 + 0x70);
                            plVar8 = (longlong *)0x0;
                            *(undefined8 *)(lVar15 + 0x70) = 0;
                            uVar20 = 0xe6;
                            uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                            *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23aaab0d0;
                          }
                          lVar10 = *(longlong *)(lVar15 + 0x10);
                          plVar9 = *(longlong **)(lVar10 + 0xe20);
                          if (plVar9 == (longlong *)0x0) {
                            plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                          }
                          else {
                            lVar12 = plVar9[3];
                            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                            *(longlong *)(lVar10 + 0xe20) = lVar12;
                            *plVar9 = 1;
                          }
                          pcVar11 = _PyRuntime_exref;
                          plVar8 = (longlong *)&DAT_23ed6a4c0;
                          plVar9[4] = 0;
                          lVar10 = *(longlong *)
                                    (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
                          lVar12 = plVar9[-1];
                          puVar17 = *(undefined8 **)(lVar10 + 8);
                          *puVar17 = plVar9 + -2;
                          plVar9[-2] = lVar10;
                          plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                          *(longlong **)(lVar10 + 8) = plVar9 + -2;
                          plVar16 = DAT_23ed6a4c0;
                          *plVar6 = *plVar6 + 1;
                          plVar9[3] = (longlong)plVar6;
                          uVar22 = DAT_23ed6cd28;
                          if (plVar16 == (longlong *)0x0) {
                            plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar16 != (longlong *)0x0) {
                              *plVar16 = *plVar16 + 1;
                              DAT_23ed6a4c0 = plVar16;
                              goto LAB_23aaaac72;
                            }
                            PyErr_PrintEx(0,0);
                            Py_Exit(1);
LAB_23aaab640:
                            plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8fe78);
                            if (plVar9 == (longlong *)0x0) {
LAB_23aaab77c:
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xec;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aaab0d0;
                            }
                            iVar5 = FUN_23a35f020(plVar9);
                            lVar10 = *plVar9 + -1;
                            if (iVar5 == -1) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar9 = lVar10;
                              if (lVar10 == 0) {
                                FUN_23a334bc0();
                              }
                              uVar20 = 0xec;
                              goto LAB_23aaab0d0;
                            }
                            *plVar9 = lVar10;
                            if (lVar10 == 0) {
                              (**(code **)(plVar9[1] + 0x30))();
                            }
                            if (iVar5 == 1) {
                              lVar12 = FUN_23ebc0cf0();
                              lVar10 = DAT_23ed8fe80;
                              if (lVar12 == 0) {
                                FUN_23e915740(lVar15,pplStack_230,DAT_23ed8fba8);
                                uVar20 = 0xed;
                                pplStack_230 = (longlong **)plStack_218;
                                uStack_228 = uStack_210;
                                plVar6 = plStack_208;
                                goto LAB_23aaab0d0;
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xed;
                              plVar6 = (longlong *)
                                       FUN_23e915840(lVar15,lVar12,DAT_23ed8fbb0,
                                                     *(undefined8 *)(lVar10 + 0x18));
                              if (plVar6 == (longlong *)0x0) {
                                pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                plVar6 = *(longlong **)(lVar15 + 0x70);
                                *(undefined8 *)(lVar15 + 0x70) = 0;
                                uVar20 = 0xed;
                                uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23aaab0d0;
                              }
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xee;
                              plVar6 = (longlong *)FUN_23e91bfe0(lVar15,plVar8,DAT_23ed8fe88);
                              if (plVar6 == (longlong *)0x0) {
                                pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                plVar6 = *(longlong **)(lVar15 + 0x70);
                                uVar20 = 0xee;
                                uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar15 + 0x70) = 0;
                                goto LAB_23aaab0d0;
                              }
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                            }
LAB_23aaab020:
                            iVar5 = FUN_23e8be270(lVar15,plVar7,DAT_23ed8fe90);
                            if (iVar5 == -1) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf0;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aaab0d0;
                            }
                            if ((iVar5 != 0) &&
                               (cVar4 = FUN_23e8d9ac0(plVar7,DAT_23ed8fe90,_Py_FalseStruct_exref),
                               cVar4 == '\0')) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf1;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23aaab0d0;
                            }
LAB_23aaaad65:
                            *(undefined4 *)(plVar2 + 5) = 0xf4;
                            plVar6 = (longlong *)FUN_23e915840(lVar15,plVar13,DAT_23ed8fe98,plVar14)
                            ;
                            if (plVar6 == (longlong *)0x0) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf4;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            }
                            else {
                              *plVar6 = *plVar6 + -1;
                              if (*plVar6 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                              plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fd68);
                              if (plVar6 != (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed8fd70);
                                *plVar6 = *plVar6 + -1;
                                if (*plVar6 == 0) {
                                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                                }
                                if (plVar9 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar2 + 5) = 0xf7;
                                  plVar6 = (longlong *)
                                           FUN_23e915840(lVar15,plVar9,DAT_23ed8fea0,plVar14);
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  if (plVar6 != (longlong *)0x0) {
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    lVar10 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
                                    plVar6 = *(longlong **)(lVar10 + 0x28);
                                    plVar2 = (longlong *)plVar6[2];
                                    *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) =
                                         *(undefined8 *)(lVar10 + 0x30);
                                    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                                    if (plVar2 != (longlong *)0x0) {
                                      plVar6[2] = 0;
                                      *plVar2 = *plVar2 + -1;
                                      if (*plVar2 == 0) {
                                        (**(code **)(plVar2[1] + 0x30))();
                                      }
                                    }
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    plVar6[0xf] = 0;
                                    pcVar11 = _Py_NoneStruct_exref;
                                    *(longlong *)_Py_NoneStruct_exref =
                                         *(longlong *)_Py_NoneStruct_exref + 1;
                                    if ((plVar7 != (longlong *)0x0) &&
                                       (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    }
                                    if ((plVar8 != (longlong *)0x0) &&
                                       (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                                    }
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      return pcVar11;
                                    }
                                    return pcVar11;
                                  }
                                }
                              }
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              uVar20 = 0xf7;
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                            }
                          }
                          else {
LAB_23aaaac72:
                            pplStack_230 = &plStack_218;
                            uStack_210 = uVar22;
                            plStack_218 = plVar14;
                            lVar10 = FUN_23e94ed00(lVar15,plVar16,pplStack_230);
                            if (lVar10 == 0) {
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar7 = *plVar7 + -1;
                              if (*plVar7 == 0) {
                                (**(code **)(plVar7[1] + 0x30))(plVar7);
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                            }
                            else {
                              plVar9[4] = lVar10;
                              plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              if (plVar6 != (longlong *)0x0) {
                                *(undefined4 *)(plVar2 + 5) = 0xe6;
                                plVar8 = (longlong *)FUN_23e914090(lVar15,plVar7,plVar6);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                *plVar6 = *plVar6 + -1;
                                if (*plVar6 == 0) {
                                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                                }
                                if (plVar8 == (longlong *)0x0) {
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  plVar8 = (longlong *)0x0;
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uVar20 = 0xe6;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  plVar7 = (longlong *)0x0;
                                  goto LAB_23aaab0d0;
                                }
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                                }
                                plVar7 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fd88);
                                if (plVar7 == (longlong *)0x0) {
LAB_23aaab450:
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  plVar8 = (longlong *)0x0;
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uVar20 = 0xe9;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  plVar7 = (longlong *)0x0;
                                  goto LAB_23aaab0d0;
                                }
                                iVar5 = FUN_23a35f020(plVar7);
                                lVar10 = *plVar7 + -1;
                                if (iVar5 == -1) {
                                  pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                  plVar6 = *(longlong **)(lVar15 + 0x70);
                                  *(undefined8 *)(lVar15 + 0x70) = 0;
                                  uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                  *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                  *plVar7 = lVar10;
                                  if (lVar10 == 0) {
                                    plVar8 = (longlong *)0x0;
                                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    uVar20 = 0xe9;
                                    plVar7 = (longlong *)0x0;
                                  }
                                  else {
                                    uVar20 = 0xe9;
                                    plVar8 = (longlong *)0x0;
                                    plVar7 = (longlong *)0x0;
                                  }
                                  goto LAB_23aaab0d0;
                                }
                                *plVar7 = lVar10;
                                if (lVar10 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                if (iVar5 != 0) {
                                  plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fd88);
                                  if (plVar6 == (longlong *)0x0) goto LAB_23aaab450;
                                  iVar5 = FUN_23e8be270(lVar15,plVar6,DAT_23ed8fe68);
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  if (iVar5 == -1) {
                                    pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                    plVar6 = *(longlong **)(lVar15 + 0x70);
                                    plVar8 = (longlong *)0x0;
                                    *(undefined8 *)(lVar15 + 0x70) = 0;
                                    uVar20 = 0xe9;
                                    uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                    *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                    plVar7 = (longlong *)0x0;
                                    goto LAB_23aaab0d0;
                                  }
                                  if (iVar5 != 0) {
                                    plVar6 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fd88);
                                    if (plVar6 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uVar20 = 0xea;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      plVar8 = (longlong *)0x0;
                                      plVar7 = (longlong *)0x0;
                                      goto LAB_23aaab0d0;
                                    }
                                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed8fe68);
                                    *plVar6 = *plVar6 + -1;
                                    if (*plVar6 == 0) {
                                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                                    }
                                    if (plVar7 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      plVar8 = (longlong *)0x0;
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uVar20 = 0xea;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      goto LAB_23aaab0d0;
                                    }
                                    plVar8 = (longlong *)
                                             FUN_23e8bbbe0(lVar15,plVar7,DAT_23ed8fe70,
                                                           _Py_NoneStruct_exref);
                                    if (plVar8 == (longlong *)0x0) {
                                      pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                                      plVar6 = *(longlong **)(lVar15 + 0x70);
                                      uVar20 = 0xeb;
                                      *(undefined8 *)(lVar15 + 0x70) = 0;
                                      uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                                      *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                                      goto LAB_23aaab0d0;
                                    }
                                    iVar5 = FUN_23a35f020(plVar8);
                                    if (iVar5 != -1) {
                                      if (iVar5 != 0) goto LAB_23aaab640;
                                      goto LAB_23aaab020;
                                    }
                                    goto LAB_23aaab77c;
                                  }
                                }
                                plVar8 = (longlong *)0x0;
                                plVar7 = (longlong *)0x0;
                                goto LAB_23aaaad65;
                              }
                              pplStack_230 = *(longlong ***)(lVar15 + 0x60);
                              plVar6 = *(longlong **)(lVar15 + 0x70);
                              *(undefined8 *)(lVar15 + 0x70) = 0;
                              uStack_228 = *(undefined8 *)(lVar15 + 0x68);
                              *(undefined1 (*) [16])(lVar15 + 0x60) = (undefined1  [16])0x0;
                              *plVar7 = *plVar7 + -1;
                              plVar8 = (longlong *)0x0;
                              if (*plVar7 == 0) {
                                (**(code **)(plVar7[1] + 0x30))(plVar7);
                                uVar20 = 0xe6;
                                plVar7 = (longlong *)0x0;
                                goto LAB_23aaab0d0;
                              }
                            }
                            plVar8 = (longlong *)0x0;
                            uVar20 = 0xe6;
                            plVar7 = (longlong *)0x0;
                          }
LAB_23aaab0d0:
                          plVar9 = DAT_23ed6a4f8;
                          if (plVar6 == (longlong *)0x0) {
                            if (DAT_23ed6a4f8 == (longlong *)0x0) {
                              plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                            }
                            else {
                              plVar6 = (longlong *)*DAT_23ed6a4f8;
                              *DAT_23ed6a4f8 = 1;
                              DAT_23ed6a4f8 = plVar6;
                              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                            }
                            pcVar11 = _PyRuntime_exref;
                            plVar9[2] = 0;
                            plVar9[3] = (longlong)plVar2;
                            *plVar2 = *plVar2 + 1;
                            lVar10 = *(longlong *)(pcVar11 + 0x1f8);
                            *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
                            lVar10 = *(longlong *)(lVar10 + 0x10);
                            *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                            lVar10 = *(longlong *)(lVar10 + 0x2e8);
                            lVar12 = plVar9[-1];
                            puVar17 = *(undefined8 **)(lVar10 + 8);
                            *puVar17 = plVar9 + -2;
                            plVar9[-2] = lVar10;
                            plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                            *(longlong **)(lVar10 + 8) = plVar9 + -2;
                            plVar16 = plVar9;
                          }
                          else {
                            plVar16 = plVar6;
                            if ((longlong *)plVar6[3] != plVar2) {
                              if (DAT_23ed6a4f8 == (longlong *)0x0) {
                                plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                              }
                              else {
                                plVar16 = (longlong *)*DAT_23ed6a4f8;
                                *DAT_23ed6a4f8 = 1;
                                DAT_23ed6a4f8 = plVar16;
                                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                              }
                              plVar9[3] = (longlong)plVar2;
                              *plVar2 = *plVar2 + 1;
                              *(undefined4 *)((longlong)plVar9 + 0x24) = uVar20;
                              pcVar11 = _PyRuntime_exref;
                              *(undefined4 *)(plVar9 + 4) = 0xffffffff;
                              lVar10 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar12 = plVar9[-1];
                              puVar17 = *(undefined8 **)(lVar10 + 8);
                              *puVar17 = plVar9 + -2;
                              plVar9[-2] = lVar10;
                              plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                              lVar12 = *plVar6;
                              *(longlong **)(lVar10 + 8) = plVar9 + -2;
                              plVar9[2] = (longlong)plVar6;
                              plVar16 = plVar9;
                              if (lVar12 == 0) {
                                (**(code **)(plVar6[1] + 0x30))(plVar6);
                              }
                            }
                          }
                          FUN_23e8bba40(plVar2,&DAT_23ec31985,plVar13,plVar14,plVar7,plVar8);
                          if (DAT_23ed90c68 == plVar2) {
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))(plVar2);
                            }
                            DAT_23ed90c68 = (longlong *)0x0;
                          }
                          lVar10 = *(longlong *)(*(longlong *)(lVar15 + 0x38) + 8);
                          plVar6 = *(longlong **)(lVar10 + 0x28);
                          plVar2 = (longlong *)plVar6[2];
                          *(undefined8 *)(*(longlong *)(lVar15 + 0x38) + 8) =
                               *(undefined8 *)(lVar10 + 0x30);
                          *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                          if (plVar2 != (longlong *)0x0) {
                            plVar6[2] = 0;
                            *plVar2 = *plVar2 + -1;
                            if (*plVar2 == 0) {
                              (**(code **)(plVar2[1] + 0x30))();
                            }
                          }
                          *plVar6 = *plVar6 + -1;
                          if (*plVar6 == 0) {
                            (**(code **)(plVar6[1] + 0x30))(plVar6);
                          }
                          plVar6[0xf] = 0;
                          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0))
                          {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0))
                          {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          FUN_23a33aa70(lVar15,pplStack_230,uStack_228,plVar16);
                          return (code *)0x0;
                        }
                        *plVar13 = *plVar13 + 1;
                        DAT_23ed6a4c0 = plVar13;
                      }
                      pplStack_158 = &plStack_140;
                      uStack_138 = uVar22;
                      puStack_1a8 = (undefined8 *)0x23aaa9ccb;
                      plStack_140 = plVar7;
                      lVar15 = FUN_23e94ed00(lVar10,DAT_23ed6a4c0,pplStack_158);
                      if (lVar15 != 0) {
                        lVar12 = *(longlong *)(lVar10 + 0x10);
                        plVar13 = *(longlong **)(lVar12 + 0xe20);
                        if (plVar13 == (longlong *)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aaaa529;
                          plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                        }
                        else {
                          lVar1 = plVar13[3];
                          *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                          *(longlong *)(lVar12 + 0xe20) = lVar1;
                          *plVar13 = 1;
                        }
                        lVar12 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                  0x2e8);
                        lVar1 = plVar13[-1];
                        puVar17 = *(undefined8 **)(lVar12 + 8);
                        *puVar17 = plVar13 + -2;
                        plVar9 = DAT_23ed8fe08;
                        plVar13[-2] = lVar12;
                        plVar13[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar17;
                        *(longlong **)(lVar12 + 8) = plVar13 + -2;
                        plVar13[3] = lVar15;
                        *plVar9 = *plVar9 + 1;
                        plVar13[4] = (longlong)plVar9;
                        puStack_1a8 = (undefined8 *)0x23aaa9d77;
                        plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          puStack_1a8 = (undefined8 *)0x23aaa9d8c;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (plVar9 != (longlong *)0x0) {
                          *(undefined4 *)(plVar2 + 5) = 0xcb;
                          puStack_1a8 = (undefined8 *)0x23aaa9daa;
                          plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aaa9dbe;
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                          }
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aaa9dce;
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          if (plVar13 == (longlong *)0x0) {
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            plVar9 = (longlong *)0x0;
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            plVar14 = (longlong *)0x0;
                            uVar20 = 0xcb;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                            goto joined_r0x00023aaa9f83;
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aaa9de9;
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          puStack_1a8 = (undefined8 *)0x23aaa9df8;
                          plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed8fe10);
                          if (plVar16 == (longlong *)0x0) {
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            plVar14 = (longlong *)0x0;
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            uVar20 = 0xd1;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            plVar9 = (longlong *)0x0;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                            goto joined_r0x00023aaa9f83;
                          }
                          puStack_1a8 = (undefined8 *)0x23aaa9e09;
                          lVar15 = FUN_23ebc0ba0();
                          if (lVar15 == 0) {
                            puStack_1a8 = (undefined8 *)0x23aaaa9a1;
                            FUN_23e915740(lVar10,pplStack_158,DAT_23ed8fdc0);
                            *plVar16 = *plVar16 + -1;
                            lVar15 = *plVar16;
                            plStack_150 = plStack_140;
                            pplStack_158 = (longlong **)uStack_138;
                            plVar13 = plStack_130;
                          }
                          else {
                            puStack_1a8 = (undefined8 *)0x23aaa9e24;
                            plVar13 = (longlong *)FUN_23e8bc2f0(lVar15,DAT_23ed8fe18);
                            if (plVar13 != (longlong *)0x0) {
                              puStack_1a8 = (undefined8 *)0x23aaa9e3f;
                              plVar9 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed8fe20);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaa9e52;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              if (plVar9 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  plVar14 = (longlong *)0x0;
                                  plVar9 = (longlong *)0x0;
                                  puStack_1a8 = (undefined8 *)0x23aaaaa09;
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                  uVar20 = 0xd1;
                                  plVar16 = DAT_23ed6a4f8;
                                  plVar3 = uStack_148;
                                }
                                else {
                                  plVar9 = (longlong *)0x0;
                                  plVar14 = (longlong *)0x0;
                                  uVar20 = 0xd1;
                                  plVar16 = DAT_23ed6a4f8;
                                  plVar3 = uStack_148;
                                }
                                goto joined_r0x00023aaa9f83;
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xd1;
                              puStack_1a8 = (undefined8 *)0x23aaa9e70;
                              plVar13 = (longlong *)FUN_23e914090(lVar10,plVar16,plVar9);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaa9e84;
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaa9e96;
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              if (plVar13 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                plVar9 = (longlong *)0x0;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                uVar20 = 0xd1;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar14 = (longlong *)0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                                goto joined_r0x00023aaa9f83;
                              }
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaa9eaf;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              *(undefined4 *)(plVar2 + 5) = 0xd2;
                              puStack_1a8 = (undefined8 *)0x23aaa9ec8;
                              plVar13 = (longlong *)FUN_23e91bfe0(lVar10,plVar8,DAT_23ed8fe28);
                              if (plVar13 == (longlong *)0x0) {
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                plVar9 = (longlong *)0x0;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                uVar20 = 0xd2;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar14 = (longlong *)0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                                goto joined_r0x00023aaa9f83;
                              }
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaa9ee8;
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              goto LAB_23aaa9862;
                            }
                            plStack_150 = *(longlong **)(lVar10 + 0x60);
                            plVar13 = *(longlong **)(lVar10 + 0x70);
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            *plVar16 = *plVar16 + -1;
                            lVar15 = *plVar16;
                          }
                          if (lVar15 == 0) {
                            plVar14 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            puStack_1a8 = (undefined8 *)0x23aaaa983;
                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                            uVar20 = 0xd1;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                          }
                          else {
                            plVar14 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            uVar20 = 0xd1;
                            plVar16 = DAT_23ed6a4f8;
                            plVar3 = uStack_148;
                          }
                          goto joined_r0x00023aaa9f83;
                        }
                      }
                      plVar14 = (longlong *)0x0;
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        plVar9 = (longlong *)0x0;
                        puStack_1a8 = (undefined8 *)0x23aaaa74d;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                        uVar20 = 0xcc;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                      }
                      else {
                        plVar9 = (longlong *)0x0;
                        uVar20 = 0xcc;
                        plVar16 = DAT_23ed6a4f8;
                        plVar3 = uStack_148;
                      }
                      goto joined_r0x00023aaa9f83;
                    }
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    *plVar16 = *plVar16 + -1;
                    lVar15 = *plVar16;
                  }
                  if (lVar15 == 0) {
                    plVar14 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aaaa671;
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                    uVar20 = 200;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  else {
                    plVar14 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    uVar20 = 200;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  goto joined_r0x00023aaa9f83;
                }
LAB_23aaa9862:
                lVar15 = *(longlong *)(DAT_23ed8fb58 + 0x20);
                if (*(char *)(lVar15 + 10) == '\0') {
                  puStack_1a8 = (undefined8 *)0x23aaaa17c;
                  plVar13 = (longlong *)FUN_23a37a020(DAT_23ed8fb58,DAT_23ed8fe30);
                  if (plVar13 == (longlong *)0x0) goto LAB_23aaa9f19;
                  lVar12 = *plVar13;
LAB_23aaaa188:
                  if (lVar12 == 0) goto LAB_23aaa9f19;
                }
                else {
                  iVar5 = *(int *)(lVar15 + 0xc);
                  if (*(int *)(lVar15 + 0xc) == 0) {
                    *(int *)(lVar15 + 0xc) = DAT_23ec107d0;
                    iVar5 = DAT_23ec107d0;
                    DAT_23ec107d0 = DAT_23ec107d0 + 1;
                  }
                  if (DAT_23ec107ac != iVar5) {
                    puStack_1a8 = (undefined8 *)0x23aaa9f09;
                    DAT_23ec107ac = iVar5;
                    DAT_23ed90c70 =
                         FUN_23e8cbd60(lVar15,DAT_23ed8fe30,*(undefined8 *)(DAT_23ed8fe30 + 0x18));
                  }
                  if (-1 < DAT_23ed90c70) {
                    lVar1 = lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f));
                    lVar12 = *(longlong *)(lVar1 + 8 + DAT_23ed90c70 * 0x10);
                    if (lVar12 != 0) goto LAB_23aaa98cf;
                    puStack_1a8 = (undefined8 *)0x23aaaa5b3;
                    DAT_23ed90c70 =
                         FUN_23e8cbd60(lVar15,DAT_23ed8fe30,*(undefined8 *)(DAT_23ed8fe30 + 0x18));
                    if (-1 < DAT_23ed90c70) {
                      lVar12 = *(longlong *)(lVar1 + 8 + DAT_23ed90c70 * 0x10);
                      goto LAB_23aaaa188;
                    }
                  }
LAB_23aaa9f19:
                  puStack_1a8 = (undefined8 *)0x23aaa9f2f;
                  plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed8fe30);
                  if ((plVar13 == (longlong *)0x0) || (lVar12 = *plVar13, lVar12 == 0)) {
                    plVar9 = (longlong *)0x0;
                    plVar14 = (longlong *)0x0;
                    puStack_1a8 = (undefined8 *)0x23aaa9f59;
                    FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fe30);
                    uVar20 = 0xd5;
                    plVar13 = plStack_130;
                    plVar16 = DAT_23ed6a4f8;
                    pplStack_158 = (longlong **)uStack_138;
                    plStack_150 = plStack_140;
                    plVar3 = uStack_148;
                    goto joined_r0x00023aaa9f83;
                  }
                }
LAB_23aaa98cf:
                puStack_1a8 = (undefined8 *)0x23aaa98de;
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed8fd58);
                if (plVar13 == (longlong *)0x0) {
                  plStack_150 = *(longlong **)(lVar10 + 0x60);
                  plVar13 = *(longlong **)(lVar10 + 0x70);
                  plVar14 = (longlong *)0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  uVar20 = 0xd5;
                  pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plVar9 = (longlong *)0x0;
                  plVar16 = DAT_23ed6a4f8;
                  plVar3 = uStack_148;
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0xd5;
                  puStack_1a8 = (undefined8 *)0x23aaa98ff;
                  plVar14 = (longlong *)FUN_23e914090(lVar10,lVar12,plVar13);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aaaa14a;
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (plVar14 == (longlong *)0x0) {
                    plStack_150 = *(longlong **)(lVar10 + 0x60);
                    plVar13 = *(longlong **)(lVar10 + 0x70);
                    plVar9 = (longlong *)0x0;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    uVar20 = 0xd5;
                    pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar16 = DAT_23ed6a4f8;
                    plVar3 = uStack_148;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0xd6;
                    puStack_1a8 = (undefined8 *)0x23aaa992f;
                    plVar9 = (longlong *)FUN_23e91bfe0(lVar10,plVar14,DAT_23ed8fe28);
                    if (plVar9 == (longlong *)0x0) {
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      uVar20 = 0xd6;
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar16 = DAT_23ed6a4f8;
                      plVar3 = uStack_148;
                    }
                    else {
                      puStack_1a8 = (undefined8 *)0x23aaa994a;
                      plVar13 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed8fe38);
                      if (plVar13 != (longlong *)0x0) {
                        puStack_1a8 = (undefined8 *)0x23aaa9965;
                        pplStack_158 = (longlong **)FUN_23e8bc2f0(plVar13,DAT_23ed8fe40);
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          puStack_1a8 = (undefined8 *)0x23aaaa160;
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (pplStack_158 != (longlong **)0x0) {
                          puStack_1a8 = (undefined8 *)0x23aaa998c;
                          iVar5 = FUN_23e912620(plVar9,pplStack_158);
                          *pplStack_158 = (longlong *)((longlong)*pplStack_158 + -1);
                          if (*pplStack_158 == (longlong *)0x0) {
                            puStack_1a8 = (undefined8 *)0x23aaa99a4;
                            (**(code **)((longlong)pplStack_158[1] + 0x30))(pplStack_158);
                          }
                          if (iVar5 != -1) {
                            if (iVar5 == 1) {
                              puStack_1a8 = (undefined8 *)0x23aaaa3b5;
                              lVar12 = FUN_23ebc0cf0();
                              lVar15 = DAT_23ed8fe48;
                              if (lVar12 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaaa927;
                                FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fba8);
                                uVar20 = 0xd9;
                                plVar13 = plStack_130;
                                plVar16 = DAT_23ed6a4f8;
                                pplStack_158 = (longlong **)uStack_138;
                                plStack_150 = plStack_140;
                                plVar3 = uStack_148;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0xd9;
                                puStack_1a8 = (undefined8 *)0x23aaaa3e2;
                                plVar13 = (longlong *)
                                          FUN_23e915840(lVar10,lVar12,DAT_23ed8fbb0,
                                                        *(undefined8 *)(lVar15 + 0x18));
                                if (plVar13 != (longlong *)0x0) {
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaaa3fb;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  pcVar11 = _Py_TrueStruct_exref;
                                  *(longlong *)_Py_TrueStruct_exref =
                                       *(longlong *)_Py_TrueStruct_exref + 1;
                                  goto LAB_23aaa9a0b;
                                }
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                uVar20 = 0xd9;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                              }
                            }
                            else {
                              puStack_1a8 = (undefined8 *)0x23aaa99bd;
                              lVar12 = FUN_23ebc0cf0();
                              lVar15 = DAT_23ed8fe50;
                              if (lVar12 == 0) {
                                puStack_1a8 = (undefined8 *)0x23aaaa7dc;
                                FUN_23e915740(lVar10,&plStack_140,DAT_23ed8fba8);
                                uVar20 = 0xdc;
                                plVar13 = plStack_130;
                                plVar16 = DAT_23ed6a4f8;
                                pplStack_158 = (longlong **)uStack_138;
                                plStack_150 = plStack_140;
                                plVar3 = uStack_148;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0xdc;
                                puStack_1a8 = (undefined8 *)0x23aaa99ea;
                                plVar13 = (longlong *)
                                          FUN_23e915840(lVar10,lVar12,DAT_23ed8fbb0,
                                                        *(undefined8 *)(lVar15 + 0x18));
                                if (plVar13 != (longlong *)0x0) {
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaaa4b7;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  pcVar11 = _Py_FalseStruct_exref;
                                  *(longlong *)_Py_FalseStruct_exref =
                                       *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23aaa9a0b:
                                  lVar15 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                                  plVar13 = *(longlong **)(lVar15 + 0x28);
                                  plVar2 = (longlong *)plVar13[2];
                                  *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) =
                                       *(undefined8 *)(lVar15 + 0x30);
                                  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                                  if (plVar2 != (longlong *)0x0) {
                                    plVar13[2] = 0;
                                    *plVar2 = *plVar2 + -1;
                                    if (*plVar2 == 0) {
                                      puStack_1a8 = (undefined8 *)0x23aaaa497;
                                      (**(code **)(plVar2[1] + 0x30))();
                                    }
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaa9a51;
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  plVar13[0xf] = 0;
                                  if ((plVar8 != (longlong *)0x0) &&
                                     (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                                    puStack_1a8 = (undefined8 *)0x23aaaa48a;
                                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                                  }
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaa9a78;
                                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                                  }
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaa9a89;
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  *plVar6 = *plVar6 + -1;
                                  if (*plVar6 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaa9a99;
                                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                                  }
                                  *plVar7 = *plVar7 + -1;
                                  if (*plVar7 == 0) {
                                    puStack_1a8 = (undefined8 *)0x23aaa9aaa;
                                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                                    return pcVar11;
                                  }
                                  return pcVar11;
                                }
                                plStack_150 = *(longlong **)(lVar10 + 0x60);
                                plVar13 = *(longlong **)(lVar10 + 0x70);
                                uVar20 = 0xdc;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                plVar16 = DAT_23ed6a4f8;
                                plVar3 = uStack_148;
                              }
                            }
                            goto joined_r0x00023aaa9f83;
                          }
                        }
                      }
                      plStack_150 = *(longlong **)(lVar10 + 0x60);
                      plVar13 = *(longlong **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      uVar20 = 0xd8;
                      pplStack_158 = *(longlong ***)(lVar10 + 0x68);
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plVar16 = DAT_23ed6a4f8;
                      plVar3 = uStack_148;
                    }
                  }
                }
joined_r0x00023aaa9f83:
                uStack_148._4_4_ = (undefined4)((ulonglong)plVar3 >> 0x20);
                DAT_23ed6a4f8 = plVar16;
                uStack_148 = plVar3;
                if (plVar13 == (longlong *)0x0) {
                  if (plVar16 == (longlong *)0x0) {
                    uStack_148 = (longlong *)CONCAT44(uStack_148._4_4_,uVar20);
                    puStack_1a8 = (undefined8 *)0x23aaaa5e8;
                    plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                    uVar20 = SUB84(uStack_148,0);
                  }
                  else {
                    DAT_23ed6a4f8 = (longlong *)*plVar16;
                    *plVar16 = 1;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcVar11 = _PyRuntime_exref;
                  plVar16[3] = (longlong)plVar2;
                  plVar16[2] = 0;
                  *plVar2 = *plVar2 + 1;
                  lVar15 = *(longlong *)(pcVar11 + 0x1f8);
                  *(undefined4 *)((longlong)plVar16 + 0x24) = uVar20;
                  *(undefined4 *)(plVar16 + 4) = 0xffffffff;
                  lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
                  lVar12 = plVar16[-1];
                  puVar17 = *(undefined8 **)(lVar15 + 8);
                  *puVar17 = plVar16 + -2;
                  plVar16[-2] = lVar15;
                  plVar16[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                  *(longlong **)(lVar15 + 8) = plVar16 + -2;
                  plVar18 = plVar16;
                  plVar3 = uStack_148;
                }
                else {
                  plVar18 = plVar13;
                  if ((longlong *)plVar13[3] != plVar2) {
                    if (plVar16 == (longlong *)0x0) {
                      uStack_148 = (longlong *)CONCAT44(uStack_148._4_4_,uVar20);
                      puStack_1a8 = (undefined8 *)0x23aaaa3a0;
                      plVar16 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                      uVar20 = SUB84(uStack_148,0);
                    }
                    else {
                      DAT_23ed6a4f8 = (longlong *)*plVar16;
                      *plVar16 = 1;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    plVar16[3] = (longlong)plVar2;
                    *plVar2 = *plVar2 + 1;
                    *(undefined4 *)((longlong)plVar16 + 0x24) = uVar20;
                    pcVar11 = _PyRuntime_exref;
                    *(undefined4 *)(plVar16 + 4) = 0xffffffff;
                    lVar15 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
                    lVar12 = plVar16[-1];
                    puVar17 = *(undefined8 **)(lVar15 + 8);
                    *puVar17 = plVar16 + -2;
                    plVar16[-2] = lVar15;
                    plVar16[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
                    lVar12 = *plVar13;
                    *(longlong **)(lVar15 + 8) = plVar16 + -2;
                    plVar16[2] = (longlong)plVar13;
                    plVar18 = plVar16;
                    plVar3 = uStack_148;
                    if (lVar12 == 0) {
                      puStack_1a8 = (undefined8 *)0x23aaaa02f;
                      uStack_148 = plVar16;
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      plVar18 = uStack_148;
                      plVar3 = uStack_148;
                    }
                  }
                }
                uStack_148 = plVar3;
                puStack_1a8 = (undefined8 *)0x23aaaa05b;
                plStack_180 = plVar8;
                plStack_178 = plVar14;
                plStack_170 = plVar9;
                FUN_23e8bba40(plVar2,"ooooo",plVar6,plVar7);
                if (DAT_23ed90c80 == plVar2) {
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aaaa290;
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  DAT_23ed90c80 = (longlong *)0x0;
                }
                lVar15 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
                plVar13 = *(longlong **)(lVar15 + 0x28);
                plVar2 = (longlong *)plVar13[2];
                *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
                *(undefined4 *)(plVar13 + 8) = 0xffffffff;
                if (plVar2 != (longlong *)0x0) {
                  plVar13[2] = 0;
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    puStack_1a8 = (undefined8 *)0x23aaaa0a1;
                    (**(code **)(plVar2[1] + 0x30))();
                  }
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aaaa0b1;
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                plVar13[0xf] = 0;
                if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aaaa0ce;
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aaaa0e3;
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                  puStack_1a8 = (undefined8 *)0x23aaaa0f9;
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aaaa109;
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  puStack_1a8 = (undefined8 *)0x23aaaa11a;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                puStack_1a8 = (undefined8 *)0x23aaaa131;
                FUN_23a33aa70(lVar10,plStack_150,pplStack_158,plVar18);
                return (code *)0x0;
              }
              *plVar6 = *plVar6 + 1;
              DAT_23ed6a4c0 = plVar6;
            }
            uStack_80 = uVar22;
            puStack_d0 = (undefined8 *)0x23aaa8bbf;
            local_88 = plVar9;
            lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
            if (lVar10 == 0) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)local_90 = *(longlong *)local_90 + -1;
              if (*(longlong *)local_90 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa94c3;
                (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                uVar20 = 0xb1;
                puStack_d0 = (undefined8 *)0x23aaa94df;
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              else {
                uVar20 = 0xb1;
              }
              goto LAB_23aaa8cbd;
            }
            plVar14[4] = lVar10;
            puStack_d0 = (undefined8 *)0x23aaa8be4;
            plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa934b;
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar6 == (longlong *)0x0) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar19 = 0xb1;
              uVar20 = 0xb1;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)local_90 = *(longlong *)local_90 + -1;
              lVar10 = *(longlong *)local_90;
              goto joined_r0x00023aaa968d;
            }
            *(undefined4 *)(plVar2 + 5) = 0xb1;
            puStack_d0 = (undefined8 *)0x23aaa8c1a;
            plVar7 = (longlong *)FUN_23e914090(param_1,local_90,plVar6);
            *(longlong *)local_90 = *(longlong *)local_90 + -1;
            if (*(longlong *)local_90 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa8c32;
              (**(code **)(*(longlong *)((longlong)local_90 + 8) + 0x30))(local_90);
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              puStack_d0 = (undefined8 *)0x23aaa939a;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (plVar7 != (longlong *)0x0) {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa8c57;
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              pcVar11 = _Py_TrueStruct_exref;
              *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23aaa9167:
              lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar6 = *(longlong **)(lVar10 + 0x28);
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
              plVar2 = (longlong *)plVar6[2];
              *(undefined4 *)(plVar6 + 8) = 0xffffffff;
              local_90 = pcVar11;
              if (plVar2 != (longlong *)0x0) {
                plVar6[2] = 0;
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  puStack_d0 = (undefined8 *)0x23aaa937c;
                  (**(code **)(plVar2[1] + 0x30))();
                }
              }
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa91b2;
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar6[0xf] = 0;
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa91d4;
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa91ef;
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                puStack_d0 = (undefined8 *)0x23aaa920e;
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                return local_90;
              }
              return local_90;
            }
          }
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar20 = 0xb1;
        }
        goto LAB_23aaa8cbd;
      }
    }
LAB_23aaa8f10:
    plVar7 = local_68;
    uVar22 = local_78._0_8_;
    uVar21 = local_78._8_8_;
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_d0 = (undefined8 *)0x23aaa8fbb;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    local_68 = (longlong *)0x0;
    local_78 = (undefined1  [16])0x0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      puStack_d0 = (undefined8 *)0x23aaa8f5b;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      puStack_d0 = (undefined8 *)0x23aaa8f79;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
  }
  uVar20 = 0xae;
  plVar9 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  local_78._8_8_ = uVar21;
  local_78._0_8_ = uVar22;
  local_68 = plVar7;
LAB_23aaa8cbd:
  plVar7 = local_68;
  plVar6 = DAT_23ed6a4f8;
  if (local_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aaa947c;
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar6[3] = (longlong)plVar2;
    plVar6[2] = 0;
    *plVar2 = *plVar2 + 1;
    lVar10 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)(plVar6 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)((longlong)plVar6 + 0x24) = uVar20;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar15 = plVar6[-1];
    puVar17 = *(undefined8 **)(lVar10 + 8);
    *puVar17 = plVar6 + -2;
    plVar6[-2] = lVar10;
    plVar6[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar10 + 8) = plVar6 + -2;
    plVar7 = plVar6;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      puStack_d0 = (undefined8 *)0x23aaa9311;
      (**(code **)(local_68[1] + 0x30))(local_68);
    }
  }
  else if ((longlong *)local_68[3] != plVar2) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      puStack_d0 = (undefined8 *)0x23aaa932c;
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar6[3] = (longlong)plVar2;
    *plVar2 = *plVar2 + 1;
    lVar10 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar6 + 0x24) = uVar20;
    *(undefined4 *)(plVar6 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar15 = plVar6[-1];
    puVar17 = *(undefined8 **)(lVar10 + 8);
    *puVar17 = plVar6 + -2;
    plVar6[-2] = lVar10;
    plVar6[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar10 + 8) = plVar6 + -2;
    plVar6[2] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    plVar7 = plVar6;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      puStack_d0 = (undefined8 *)0x23aaa9227;
      (**(code **)(local_68[1] + 0x30))();
    }
  }
  local_68 = plVar7;
  puStack_d0 = (undefined8 *)0x23aaa8d95;
  local_a8 = plVar9;
  FUN_23e8bba40(plVar2,&DAT_23ec31911,plVar13,plVar8);
  if (DAT_23ed90c90 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      puStack_d0 = (undefined8 *)0x23aaa8f90;
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23ed90c90 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar10 + 0x28);
  plVar2 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar2 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      puStack_d0 = (undefined8 *)0x23aaa8ddb;
      (**(code **)(plVar2[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    puStack_d0 = (undefined8 *)0x23aaa8deb;
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar2 = local_68;
  plVar6[0xf] = 0;
  uVar22 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_d0 = (undefined8 *)0x23aaa8e25;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    puStack_d0 = (undefined8 *)0x23aaa8e3b;
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar13 = *plVar13 + -1;
  local_68 = plVar2;
  local_78._0_8_ = uVar22;
  local_78._8_8_ = uVar21;
  if (*plVar13 == 0) {
    puStack_d0 = (undefined8 *)0x23aaa8eca;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  puStack_d0 = (undefined8 *)0x23aaa8e64;
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
