/* ===== 23e8116a0 workers.fishing.memory_reeling:MemoryReelingTracker._get_modules ===== */
/* ghidra_name=FUN_23e8116a0 entry=23e8116a0 size=5624 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e8116a0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong lVar18;
  undefined4 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_b0;
  undefined1 local_98 [16];
  longlong *local_88;
  longlong *local_78;
  longlong *plStack_70;
  longlong local_68;
  
  plVar10 = _DAT_23eede860;
  plVar2 = (longlong *)*param_3;
  local_88 = (longlong *)0x0;
  local_98 = (undefined1  [16])0x0;
  if (_DAT_23eede860 == (longlong *)0x0) {
LAB_23e8116fd:
    _DAT_23eede860 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9c0,DAT_23eedd0f8,0x48);
  }
  else {
    lVar18 = *_DAT_23eede860;
    if (1 < lVar18) {
      *_DAT_23eede860 = lVar18 + -1;
      goto LAB_23e8116fd;
    }
    if (_DAT_23eede860[2] != 0) {
      *_DAT_23eede860 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e8116fd;
    }
  }
  plVar3 = _DAT_23eede860;
  lVar18 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eede860 + 9;
  lVar16 = *(longlong *)(lVar18 + 8);
  _DAT_23eede860[0xf] = lVar16;
  *(longlong **)(lVar18 + 8) = plVar10;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar20 = _DAT_23eedd140;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,uVar20);
  plVar10 = (longlong *)0x0;
  if (plVar8 == (longlong *)0x0) {
LAB_23e811c83:
    plVar8 = *(longlong **)(param_1 + 0x70);
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar17 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar19 = 0x172;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e8119e1;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar9 == (longlong *)0x0) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    plVar17 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar19 = 0x172;
    local_b0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e8119e1;
  }
  *(undefined4 *)(plVar3 + 5) = 0x172;
  plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar9,_DAT_23eedd500);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) goto LAB_23e811c83;
  iVar7 = FUN_23a35f020(plVar10);
  plVar8 = DAT_23ed6ccf0;
  if (iVar7 == -1) {
    local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    uVar19 = 0x173;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    if (iVar7 == 0) {
      plVar9 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      local_b0 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_b8 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
      plVar15 = (longlong *)0x0;
      goto LAB_23e811847;
    }
    plVar9 = (longlong *)FUN_23a388310(plVar10);
    if (plVar9 == (longlong *)0x0) {
      uVar20 = *(undefined8 *)(param_1 + 0x60);
      uVar21 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
      if ((plVar11 == (longlong *)0x0) &&
         (plVar11 = (longlong *)FUN_23a3c1b70(param_1,local_98,0,2), plVar11 == (longlong *)0x0)) {
        plVar12 = (longlong *)0x0;
      }
      else {
        plVar12 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
        if (((plVar12 != (longlong *)0x0) ||
            (plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_98,1,2), plVar12 != (longlong *)0x0))
           && (cVar6 = FUN_23a3884a0(param_1,local_98,plVar9,2), cVar6 != '\0')) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eedd520);
          if (plVar8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            uVar19 = 0x176;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            local_c0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          lVar18 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar18 + 10) == '\0') {
            plVar9 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd550);
            if (plVar9 == (longlong *)0x0) goto LAB_23e812470;
            lVar16 = *plVar9;
LAB_23e812462:
            if (lVar16 == 0) goto LAB_23e812470;
          }
          else {
            iVar7 = *(int *)(lVar18 + 0xc);
            if (*(int *)(lVar18 + 0xc) == 0) {
              *(int *)(lVar18 + 0xc) = DAT_23ec155d8;
              iVar7 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (_DAT_23ec155b4 != iVar7) {
              _DAT_23ec155b4 = iVar7;
              _DAT_23eede858 =
                   FUN_23e8cbd60(lVar18,_DAT_23eedd550,*(undefined8 *)(_DAT_23eedd550 + 0x18));
            }
            if (-1 < _DAT_23eede858) {
              lVar1 = lVar18 + 0x20 + (1L << (*(byte *)(lVar18 + 9) & 0x3f));
              lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eede858 * 0x10);
              if (lVar16 != 0) goto LAB_23e811f24;
              _DAT_23eede858 =
                   FUN_23e8cbd60(lVar18,_DAT_23eedd550,*(undefined8 *)(_DAT_23eedd550 + 0x18));
              if (-1 < _DAT_23eede858) {
                lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eede858 * 0x10);
                goto LAB_23e812462;
              }
            }
LAB_23e812470:
            plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd550);
            if ((plVar9 == (longlong *)0x0) || (lVar16 = *plVar9, lVar16 == 0)) {
              FUN_23e915740(param_1,local_98,_DAT_23eedd550);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              local_b0 = (longlong *)0x0;
              uVar19 = 0x176;
              plVar17 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              plVar8 = local_88;
              plVar15 = DAT_23ed6a4f8;
              goto joined_r0x00023e8119e1;
            }
          }
LAB_23e811f24:
          *(undefined4 *)(plVar3 + 5) = 0x176;
          local_78 = plVar11;
          plStack_70 = plVar12;
          local_68 = lVar16;
          local_c0 = (longlong *)FUN_23e956150(param_1,plVar8,&local_78);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (local_c0 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x176;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          iVar7 = FUN_23a35f020(local_c0);
          plVar8 = DAT_23ed6ccf0;
          if (iVar7 == -1) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x177;
            plVar17 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar9 = (longlong *)0x0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          if (iVar7 == 0) {
            plVar9 = (longlong *)0x0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
            plVar15 = (longlong *)0x0;
LAB_23e811847:
            lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar3 = *(longlong **)(lVar18 + 0x28);
            plVar17 = (longlong *)plVar3[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
            *(undefined4 *)(plVar3 + 8) = 0xffffffff;
            if (plVar17 != (longlong *)0x0) {
              plVar3[2] = 0;
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))();
              }
            }
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))(plVar3);
            }
            plVar3[0xf] = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            plVar17 = plVar8;
            if (plVar11 != (longlong *)0x0) {
LAB_23e8118aa:
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
LAB_23e8121f0:
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
            }
            if (plVar12 == (longlong *)0x0) goto LAB_23e8118c4;
LAB_23e8118b9:
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
LAB_23e8118c4:
            if ((local_c0 != (longlong *)0x0) &&
               (lVar18 = *local_c0, *local_c0 = lVar18 + -1, lVar18 + -1 == 0)) {
              (**(code **)(local_c0[1] + 0x30))(local_c0);
            }
            if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if ((local_b8 != (longlong *)0x0) &&
               (lVar18 = *local_b8, *local_b8 = lVar18 + -1, lVar18 + -1 == 0)) {
              (**(code **)(local_b8[1] + 0x30))(local_b8);
            }
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((local_b0 != (longlong *)0x0) &&
               (lVar18 = *local_b0, *local_b0 = lVar18 + -1, lVar18 + -1 == 0)) {
              (**(code **)(local_b0[1] + 0x30))(local_b0);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 == 0) {
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return plVar17;
            }
            return plVar17;
          }
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedd378);
          if (plVar8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x179;
            local_b0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_b8 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          plVar17 = (longlong *)FUN_23e8bf9b0(local_c0,_DAT_23eedd558);
          plVar9 = _DAT_23eedd3a0;
          if (plVar17 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_88 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            lVar18 = *plVar8;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar8 = lVar18 + -1;
            plVar17 = (longlong *)0x0;
            if (lVar18 + -1 == 0) {
              plVar9 = (longlong *)0x0;
              FUN_23a334bc0(plVar8);
              local_b0 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              uVar19 = 0x179;
              plVar8 = local_88;
              plVar15 = DAT_23ed6a4f8;
            }
            else {
              plVar9 = (longlong *)0x0;
              uVar19 = 0x179;
              local_b0 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              plVar8 = local_88;
              plVar15 = DAT_23ed6a4f8;
            }
            goto joined_r0x00023e8119e1;
          }
          *(undefined4 *)(plVar3 + 5) = 0x179;
          plStack_70 = plVar9;
          local_78 = plVar17;
          plVar9 = (longlong *)FUN_23e94ed00(param_1,plVar8,&local_78);
          lVar18 = *plVar8;
          *plVar8 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar9 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            uVar19 = 0x179;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          plVar8 = (longlong *)FUN_23e8bd600(param_1,plVar9);
          if (plVar8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            uVar19 = 0x17a;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_b0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_b8 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          lVar18 = *plVar8 + -1;
          if ((plVar8[2] != 1) || ((int)plVar8[3] != 4)) {
            *plVar8 = lVar18;
            if (lVar18 == 0) {
              (**(code **)(plVar8[1] + 0x30))();
            }
            plVar8 = DAT_23ed6ccf0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
            plVar15 = (longlong *)0x0;
            goto LAB_23e811847;
          }
          *plVar8 = lVar18;
          if (lVar18 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          lVar18 = FUN_23e8dc840();
          plVar8 = _DAT_23eedd3b8;
          if (lVar18 == 0) {
            plVar17 = (longlong *)0x0;
            FUN_23e915740(param_1,local_98,_DAT_23eedd388);
            uVar19 = 0x17c;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            plVar8 = local_88;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          *(undefined4 *)(plVar3 + 5) = 0x17c;
          local_78 = plVar8;
          plStack_70 = plVar9;
          plVar8 = (longlong *)FUN_23e954670(param_1,lVar18,_DAT_23eedd390,&local_78);
          if (plVar8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x17c;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_b0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          local_b8 = (longlong *)FUN_23a388650(param_1,plVar8,DAT_23ed6ccf0,0);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            FUN_23a334bc0(plVar8);
          }
          if (local_b8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x17c;
            local_b0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          plVar8 = (longlong *)FUN_23e8bf9b0(local_c0,_DAT_23eedd560);
          if (plVar8 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar17 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar19 = 0x17d;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_b0 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          plVar17 = (longlong *)FUN_23e8c09e0(plVar8,local_b8);
          lVar18 = *plVar8;
          *plVar8 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            FUN_23a334bc0(plVar8);
          }
          uVar20 = _DAT_23eedd528;
          if (plVar17 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x17d;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_b0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          *(undefined4 *)(plVar3 + 5) = 0x17e;
          local_b0 = (longlong *)FUN_23e915840(param_1,plVar2,uVar20,plVar17);
          if (local_b0 == (longlong *)0x0) {
            local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0x17e;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e8119e1;
          }
          *(undefined4 *)(plVar3 + 5) = 0x17f;
          plVar8 = (longlong *)FUN_23e915840(param_1,plVar2,_DAT_23eedd530);
          if (plVar8 != (longlong *)0x0) {
            iVar7 = FUN_23a35f020(plVar8);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              FUN_23a334bc0();
            }
            plVar8 = DAT_23ed6ccf0;
            if (iVar7 != -1) {
              plVar15 = plVar17;
              if (iVar7 == 0) {
                *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
                goto LAB_23e811847;
              }
              plVar13 = (longlong *)FUN_23e8bc2f0(plVar2);
              plVar8 = _DAT_23eedd568;
              if (plVar13 != (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                *plVar8 = *plVar8 + 1;
                plVar14[3] = (longlong)plVar8;
                lVar18 = FUN_23e94f9d0(param_1,plVar17);
                if (lVar18 == 0) {
                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_88 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    FUN_23a334bc0(plVar13);
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  uVar19 = 0x181;
                  plVar8 = local_88;
                  plVar15 = DAT_23ed6a4f8;
                  goto joined_r0x00023e8119e1;
                }
                plVar14[4] = lVar18;
                plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar8 == (longlong *)0x0) {
                  local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_88 = *(longlong **)(param_1 + 0x70);
                  uVar19 = 0x181;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar13 = *plVar13 + -1;
                  plVar8 = local_88;
                  plVar15 = DAT_23ed6a4f8;
                  if (*plVar13 == 0) {
                    FUN_23a334bc0(plVar13);
                    uVar19 = 0x181;
                    plVar8 = local_88;
                    plVar15 = DAT_23ed6a4f8;
                  }
                  goto joined_r0x00023e8119e1;
                }
                *(undefined4 *)(plVar3 + 5) = 0x181;
                plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0(plVar13);
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  FUN_23a334bc0(plVar8);
                }
                if (plVar14 != (longlong *)0x0) {
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                  *plVar17 = *plVar17 + 1;
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                    goto LAB_23e8118aa;
                  }
                  lVar18 = *plVar11;
                  *plVar11 = lVar18 + -1;
                  if (lVar18 + -1 == 0) goto LAB_23e8121f0;
                  goto LAB_23e8118b9;
                }
              }
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar19 = 0x181;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar15 = DAT_23ed6a4f8;
              goto joined_r0x00023e8119e1;
            }
          }
          local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar8 = *(longlong **)(param_1 + 0x70);
          uVar19 = 0x17f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar15 = DAT_23ed6a4f8;
          goto joined_r0x00023e8119e1;
        }
      }
      plVar8 = local_88;
      uVar20 = local_98._0_8_;
      uVar21 = local_98._8_8_;
      local_88 = (longlong *)0x0;
      local_98 = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      local_88 = (longlong *)0x0;
      local_98 = (undefined1  [16])0x0;
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
    uVar19 = 0x175;
    local_98._8_8_ = uVar21;
    local_98._0_8_ = uVar20;
  }
  plVar17 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  local_b0 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  local_c0 = (longlong *)0x0;
  plVar15 = DAT_23ed6a4f8;
joined_r0x00023e8119e1:
  DAT_23ed6a4f8 = plVar15;
  local_88 = plVar8;
  if (plVar8 == (longlong *)0x0) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
    pcVar5 = _PyRuntime_exref;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
    lVar16 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar18 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar18;
    plVar15[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar18 + 8) = plVar15 + -2;
    plVar8 = plVar15;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))(local_88);
    }
  }
  else if ((longlong *)plVar8[3] != plVar3) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
    pcVar5 = _PyRuntime_exref;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
    lVar16 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar18 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar18;
    plVar15[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar18 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    plVar8 = plVar15;
    if ((local_88 != (longlong *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
      (**(code **)(local_88[1] + 0x30))();
    }
  }
  local_88 = plVar8;
  FUN_23e8bba40(plVar3,"ooooooooo",plVar2,plVar10,plVar11,plVar12,local_c0,plVar9,local_b8,plVar17,
                local_b0);
  if (_DAT_23eede860 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede860 = (longlong *)0x0;
  }
  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar18 + 0x28);
  plVar8 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar8 = local_88;
  plVar3[0xf] = 0;
  uVar20 = local_98._0_8_;
  uVar21 = local_98._8_8_;
  local_98 = (undefined1  [16])0x0;
  local_88 = (longlong *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar18 = *local_c0, *local_c0 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar18 = *local_b8, *local_b8 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((local_b0 != (longlong *)0x0) &&
     (lVar18 = *local_b0, *local_b0 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(local_b0[1] + 0x30))(local_b0);
  }
  *plVar2 = *plVar2 + -1;
  local_88 = plVar8;
  local_98._0_8_ = uVar20;
  local_98._8_8_ = uVar21;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88);
  return (longlong *)0x0;
}
